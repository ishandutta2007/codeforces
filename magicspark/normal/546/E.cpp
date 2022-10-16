/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
struct edge{
    int to,flow,rev;
};
vector<edge>g[222];
void add_edge(int u,int v,int c){
    g[u].push_back((edge){v,c,(int)g[v].size()});
    g[v].push_back((edge){u,0,(int)g[u].size()-1});
}
int q[222];
int dist[222];
bool bfs(int s,int t){
    memset(dist,0x3f3f3f3f,sizeof(dist));
    dist[s]=0;
    int b=0,e=1;q[0]=s;
    while(b<e){
        int x=q[b++];
        for(int i=0;i<g[x].size();i++){
            if(dist[g[x][i].to]==0x3f3f3f3f&&g[x][i].flow>0){
                q[e++]=g[x][i].to;
                dist[g[x][i].to]=dist[x]+1;
            }
        }
    }
    return dist[t]!=0x3f3f3f3f;
}
int dfs(int x,int to,int f){
    if(x==to)return f;
    int ret=0;
    for(int i=0;i<g[x].size();i++){
        if(g[x][i].flow>0 && dist[g[x][i].to]==dist[x]+1){
            int tmp=dfs(g[x][i].to,to,min(g[x][i].flow,f-ret));
            g[x][i].flow-=tmp;
            g[g[x][i].to][g[x][i].rev].flow+=tmp;
            ret+=tmp;
            if(ret>=f)break;
        }
    }
    return ret;
}
int max_flow(int s,int t){
    int ret=0;
    while(bfs(s,t)){
        ret+=dfs(s,t,INT_MAX);
    }
    return ret;
}
int n,m,S,T;
int a[105],b[105];
int ans[105][105];
inline int L(int x){return x;}
inline int R(int x){return 101+x;} 
int main(){
	cin>>n>>m;
	S=220;T=221;
	int sa=0,sb=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];sa+=a[i];
		add_edge(S,L(i),a[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];sb+=b[i];
		add_edge(R(i),T,b[i]);
	}
	for(int i=1;i<=n;i++){
		add_edge(L(i),R(i),inf);
	}
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		add_edge(L(x),R(y),inf);
		add_edge(L(y),R(x),inf);
	}
	int res=max_flow(S,T);
	if(sa!=sb||res!=sb){
		puts("NO");
	}else{
		puts("YES");
		for(int i=1;i<=n;i++){
			int ind=L(i);
			for(auto e:g[ind]){
				for(int j=1;j<=n;j++){
					if(e.to==R(j)){
						ans[i][j]=inf-e.flow;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}