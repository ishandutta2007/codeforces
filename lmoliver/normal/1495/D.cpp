#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
typedef vector<int> V;

template<class T=int>
T read(){
	T x=0;
	char ch=0;
	bool f=false;
	while(!isdigit(ch))f|=(ch=getchar())=='-';
	for(;isdigit(ch);ch=getchar())x=x*10+(ch^'0');
	return f?-x:x;
}

const int N=4.4e2;
int e[N][N];
V es[N];
V tf[N][N];
int dis[N][N];

void bfs(int s){
	memset(dis[s],0x3f,sizeof(dis[s]));
	queue<int> q;
	dis[s][s]=0;
	q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		int t=dis[s][x]+1;
		for(int v:es[x]){
			if(dis[s][v]>=t){
				tf[s][v].push_back(x);
				if(dis[s][v]>t){
					q.push(v);
					dis[s][v]=t;
				}
			}
		}
	}
	D(i,N)sort(tf[s][i].begin(),tf[s][i].end());
}

const int MOD=998244353;
int main(){
	int n=read(),m=read();
	D(_,m){
		int u=read(),v=read();
		es[u].push_back(v);
		es[v].push_back(u);
	}
	int qwq=1;
	F(i,1,n){
		bfs(i);
	}
	F(a,1,n)F(b,1,n){
		int ans=qwq;
		if(ans){
			static bool ir[N];
			memset(ir,false,sizeof(ir));
			for(int v=b;;v=tf[a][v][0]){
				ir[v]=true;	
				if(v==a)break;
			}
			int dd=dis[a][b];
			F(i,1,n)if(dis[a][i]+dis[i][b]==dd&&!ir[i]){
				ans=0;
				break;
			}
			if(ans){
				F(i,1,n)if(!ir[i]){
					int qaq=0;
					auto it1=tf[a][i].begin();
					auto it2=tf[b][i].begin();
					while(it1!=tf[a][i].end()&&it2!=tf[b][i].end()){
						bool aa=*it1<=*it2;
						bool bb=*it2<=*it1;
						if(aa&&bb)qaq++; 
						if(aa)it1++;
						if(bb)it2++;
					}
					// cerr<<"("<<qaq<<")";
					ans=(LL)ans*qaq%MOD;
				}
			}
		}
		printf("%d%c",ans," \n"[b==n]);
	}
	return 0;
}