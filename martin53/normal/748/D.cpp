#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42,inf=1e9;
int n,k;
string inp[nmax];
int a[nmax];
map<string, priority_queue<int>/*value*/> seen,emp;
bool pal(int ind)
{
    int SZ=inp[ind].size();
    for(int j=0;j<SZ;j++)
        if(inp[ind][j]!=inp[ind][SZ-1-j])return 0;
    return 1;
}
long long maxi[nmax][2];
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>k>>n;
for(int i=1;i<=k;i++)cin>>inp[i]>>a[i];
long long ans=0;
for(int i=1;i<=k;i++)
    if(pal(i)==0)
    {
        seen[inp[i]].push(a[i]);
    }

for(int i=1;i<=k;i++)
    if(pal(i)==0)
    {
        string s=inp[i];
        reverse(s.begin(),s.end());
        if(s<inp[i])
        {
            int v1=(seen[inp[i]].size()?seen[inp[i]].top():-1e9);
            int v2=(seen[s].size()?seen[s].top():-1e9);
            if(v1+v2>0)
            {
                ans=ans+v1+v2;
                seen[inp[i]].pop();
                seen[s].pop();
            }
        }
    }
//cout<<ans<<endl;
seen=emp;
for(int i=1;i<=k;i++)
    if(pal(i))
    {
        seen[inp[i]].push(a[i]);
    }

long long bonus=0;
int ind=0;
for(auto k:seen)
{
    long long now=0;
    bool par=0;
    while(k.second.size())
    {
        now=now+k.second.top();
        par=!par;
        maxi[ind][par]=max(maxi[ind][par],now);
        k.second.pop();
    }
    ind++;
}
for(int i=0;i<ind;i++)
    ans=ans+maxi[i][0];
for(int i=0;i<ind;i++)
    bonus=max(bonus,maxi[i][1]-maxi[i][0]);
cout<<ans+bonus<<endl;
return 0;
}