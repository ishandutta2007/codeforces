#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42,mmax=200+5;
int n;
struct letter
{
    int s,t,d,w;
};
int m,k;
letter inp[nmax];
bool cmp(letter a,letter b)
{
    return a.s<b.s;
}
pair<int/*win*/,int/*time*/> help[nmax];
set< pair< pair<int/*win*/,int/*time to stop*/>, int/*index*/> >s;
long long dp[nmax][mmax];
int ask(int t)
{
    if(s.size()==0)return -1;
    set< pair< pair<int/*win*/,int/*time to stop*/>, int/*index*/> >::iterator it=s.end();
    it--;
    pair< pair<int/*win*/,int/*time to stop*/>, int/*index*/> now=*it;
    if(inp[now.second].t<t)
    {
        s.erase(now);
        return ask(t);
    }
    return now.second;
}
long long rec(int pos,int block)
{
    if(pos>n)return 0;
    if(dp[pos][block]!=-1)return dp[pos][block];
    long long ret=rec(help[pos].second+1,block)+help[pos].first;//do not block
    //block
    if(block)ret=min(ret,rec(pos+1,block-1));
    dp[pos][block]=ret;
    return ret;
}
int main()
{
cin>>n>>m>>k;
for(int i=1;i<=k;i++)cin>>inp[i].s>>inp[i].t>>inp[i].d>>inp[i].w;
sort(inp+1,inp+k+1,cmp);
int j=1;
for(int i=1;i<=n;i++)
{
    while(j<=k&&inp[j].s==i)
    {
        s.insert({{inp[j].w,inp[j].d},j});
        j++;
    }
    int id=ask(i);
    if(id==-1)help[i]={0,i};
    else help[i]={inp[id].w,inp[id].d};
    //cout<<i<<" -> "<<help[i].first<<" "<<help[i].second<<endl;
}
memset(dp,-1,sizeof(dp));
cout<<rec(1,m)<<endl;
return 0;
}