#include<bits/stdc++.h>
using namespace std;
const int nmax=5e5+42;
int n,c;
int arr[nmax];
vector<int> seen[nmax];
vector<int> help;
vector<int> vals={};
int cnt(int l,int r)
{
    int p=lower_bound(help.begin(),help.end(),l)-help.begin();
    int q=upper_bound(help.begin(),help.end(),r)-help.begin();
    return q-p;
}
int ask(int pos)
{
    vals={};
    for(int k=0;k<seen[pos].size();k++)
    {
        if(k)vals.push_back(-cnt(seen[pos][k-1],seen[pos][k]));
        vals.push_back(1);
    }
    int mx=0;
    int now=0;
    for(auto k:vals)
    {
        now=max(now+k,k);
        mx=max(mx,now);
    }
    return mx;
}
int main()
{
scanf("%i%i",&n,&c);
int co=0;
for(int i=1;i<=n;i++)
{
    scanf("%i",&arr[i]);
    if(arr[i]!=c)seen[arr[i]].push_back(i);
    else
    {
    co++;
    help.push_back(i);
    }
}
int ans=co;
for(int i=1;i<nmax;i++)
    if(seen[i].size())ans=max(ans,co+ask(i));
printf("%i\n",ans);
return 0;
}