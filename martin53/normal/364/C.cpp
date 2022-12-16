#include<bits/stdc++.h>
using namespace std;
const int nmax=5e3+42;
int primes[10]={2,3,5,7,11,13,17,19,23,29};
int k,lim;
int border=0;
vector<int> nums[10];
set<int> banned;
int output[nmax];
int aim[10];

int in=0;

void gen(int num,int id)
{
    if(id>border)
    {
        in++;
        for(int i=0;i<=border;i++)
            if(num%primes[i]==0)
            nums[i].push_back(num);
        return;
    }
    int mult=1;
    while(mult*num<=lim)
    {
        gen(num*mult,id+1);
        mult=mult*primes[id];
    }
}
int cnt(int a)
{
    int ret=0;
    for(int i=0;i<=border;i++)
        if(a%primes[i]==0)ret++;
    return ret;
}
bool cmp(int a,int b)
{
    return cnt(a)>cnt(b);
}
void solve()
{
    in=0;
    for(int i=0;i<=border;i++)
        nums[i]={};

    gen(1,0);
    if(in<k)return;

    int total=0;
    for(int i=0;i<=border;i++)
        if(nums[i].size()<k)return;

    total=0;
    for(int i=0;i<=border;i++)
        total=total+nums[i].size();

    for(int i=0;i<=border;i++)
        sort(nums[i].begin(),nums[i].end(),cmp);

    //for(int i=0;i<=border;i++)cout<<nums[i].size()<<" ";cout<<endl;

    banned={};
    for(int i=0;i<=border;i++)
        aim[i]=(k+1)/2;

    for(int i=1;i<=k;i++)
    {
        int mx=0;
        for(int j=1;j<=border;j++)
            if(aim[mx]<aim[j])mx=j;
        while(banned.count(nums[mx][0]))nums[mx].erase(nums[mx].begin(),nums[mx].begin()+1);
        for(auto p:nums[mx])
            if(banned.count(p)==0)
            {
                output[i]=p;
                banned.insert(p);
                for(int j=0;j<=border;j++)
                    if(p%primes[j]==0)aim[j]--;
                break;
            }
    }

    bool ok=1;
    for(int i=0;i<=border;i++)
        if(aim[i]>0)return;

    for(int i=1;i<=k;i++)cout<<output[i]<<" ";cout<<endl;
    exit(0);
}
int main()
{
cin>>k;
lim=2*k*k;
for(int i=0;i<10;i++)
{
    solve();
    border++;
}
assert(0==1);
return 0;
}