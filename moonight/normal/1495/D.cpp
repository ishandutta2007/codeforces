/*
Codeforces 1495A. Diamond Miner
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(int i=0;i<a.size();++i)
inline ll rd()
{
	char c=getchar();ll x=0,w=1;
	while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x*w;
}
const int N=405,P=998244353;
int n,m,d[N][N],v[N];
vector<int>e[N],g[N];
int main()
{
    n=rd();m=rd();
    rep(i,1,n)rep(j,1,n)d[i][j]=i==j?0:1e9;
    rep(i,1,m)
    {
        int u=rd(),v=rd();d[u][v]=1;d[v][u]=1;
        e[u].push_back(v);e[v].push_back(u);
    }
    rep(k,1,n)rep(i,1,n)rep(j,1,n)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    rep(i,1,n)
    {
        rep(j,1,n)
        {
            rep(k,0,n)v[k]=0,g[k].clear();
            rep(k,1,n)if(d[i][k]+d[k][j]==d[i][j])v[d[i][k]]++;
            int ff=0;
            rep(k,0,n)if(v[k]>1)ff=1;
            if(ff)
            {
                printf("0 ");
                continue;
            }
            rep(k,1,n)g[d[i][k]].push_back(k);
            rep(k,0,n)v[k]=0;
            rep(k,1,n)if(d[i][k]+d[k][j]==d[i][j])v[k]=1;
            int ans=1;
            rep(k,1,n)
            {
                if(!g[k].size())break;
                fore(t1,g[k])
                {
                    int x=g[k][t1];
                    if(v[x])continue;
                    int cc=0;
                    fore(t2,e[x])
                    {
                        int y=e[x][t2];
                        if(d[i][y]+1!=d[i][x])continue;
                        if(d[j][y]+1==d[j][x])cc++;
                    }
                    ans=1ll*ans*cc%P;
                }
            }
            printf("%d ",ans);
        }
        puts("");
    }
    return 0;
}