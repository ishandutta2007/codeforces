/*
#include<bits/stdc++.h>
using namespace std;
const int nmax=19;
vector< pair<int,int> > dp[1<<nmax];
bool solved[1<<nmax];

vector<pair<int,int>> take_max(vector<pair<int,int>> a,vector<pair<int,int>> b)
{
    if(a.size()<b.size())return b;
    return a;
}

vector<pair<int,int>> rec(int state/*1-> not used*//*)
{
    if(solved[state])return dp[state];
    if(state==0)return {};

    vector<pair<int,int>> ans={},now;
    for(int i=1;(1<<i)<=state;i++)
        if((state&(1<<i)))
        {
            ans=take_max(ans,rec(state-(1<<i)));
        }

    for(int i=1;(1<<i)<=state;i++)
        for(int j=i+1;(1<<j)<=state;j++)
        if((state&(1<<i))&&(state&(1<<j))&&i!=j&&__gcd(i,j)!=1)
        {
            now=rec(state-(1<<i)-(1<<j));
            now.push_back({i,j});
            ans=take_max(ans,now);
        }
    dp[state]=ans;
    solved[state]=1;
    return ans;
}
int main()
{

    for(int i=1;i<nmax;i++)
    {
        cout<<"n= "<<i<<endl;
        cout<<rec((1<<(i+1))-2).size()<<endl;
        for(auto k:rec((1<<(i+1))-2))cout<<k.first<<" "<<k.second<<endl;
    }
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n;
bool prime[nmax];/*0-> prime*/
set<int> numbers[nmax];
bool taken[nmax];
bool done[nmax];
vector< pair<int,int> > outp;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
cin>>n;
prime[1]=1;
prime[0]=1;
int p=2;
while(p*p<=n)
{
    for(int j=p*p;j<=n;j=j+p)prime[j]=1;
    p++;
    while(prime[p])p++;
}

//for(int i=1;i<=n;i++)cout<<i<<" -> "<<prime[i]<<endl;

for(p=2;p<=n;p++)
    if(prime[p]==0)
    {
        for(int j=p;j<=n;j=j+p)numbers[p].insert(j);
    }

for(int i=n;i>=1;i--)
    if(prime[i]==0)
    {
        set<int> help;
        help.clear();
        for(auto k:numbers[i])
            if(done[k]==0)
            {
            help.insert(k);
            }
        numbers[i]=help;
        //cout<<i<<" -> "<<numbers[i].size()<<endl;
        if(numbers[i].size()<2)continue;
        int prev_odd=0;
        for(auto k:numbers[i])
        {
            if(k%2==1)
            {
                if(prev_odd==0)prev_odd=k;
                else
                {
                outp.push_back({prev_odd,k});
                done[prev_odd]=1;
                done[k]=1;
                prev_odd=0;
                }
            }
        }

        if(prev_odd)
        {
        bool good=0;
        for(auto k:numbers[i])
            if(k%2==0&&done[k]==0)
            {
            outp.push_back({prev_odd,k});
            done[prev_odd]=1;
            done[k]=1;
            good=1;
            break;
            }
        assert(good);
        }

    }

int prev_even=0;
for(int i=2;i<=n;i=i+2)
    if(done[i]==0)
    {
        if(prev_even==0)prev_even=i;
        else
        {
        outp.push_back({prev_even,i});
        done[prev_even]=1;
        done[i]=1;
        prev_even=0;
        }
    }
cout<<outp.size()<<endl;
for(auto k:outp)cout<<k.first<<" "<<k.second<<endl;
return 0;
}