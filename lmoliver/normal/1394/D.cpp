#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
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

const int N=200200;
int t[N],h[N];
LL dp[N][2];
V es[N];

const LL INF=1e18;
void dfs(int x,int fa=-1){
	for(int v:es[x])if(v!=fa){
		dfs(v,x);
	}
	int dg=es[x].size();
	D(u,2){//u:is up
		int oc=0,ic=0;
		if(fa!=-1)(u?oc:ic)++;
		bool ok=fa==-1?u==0:u?h[x]<=h[fa]:h[fa]<=h[x];
		// cerr<<"? "<<x<<" "<<u<<endl;
		LL &d=dp[x][u];
		d=INF;
		priority_queue<LL> pq;
		LL cc=0;
		if(ok){
			for(int v:es[x])if(v!=fa){
				LL v0=dp[v][0];
				LL v1=dp[v][1];
				if(v0<INF&&v1<INF){
					oc++;
					cc+=v0;
					pq.push(v0-v1);
				}
				else if(v0<INF){
					oc++;
					cc+=v0;
				}
				else{
					ic++;
					cc+=v1;
				}
			}
			// cerr<<dg<<endl;
			// cerr<<oc<<endl;
			// cerr<<ic<<endl;
#define COST (cc+(LL)t[x]*(dg-min(oc,ic)))
			d=COST;
			while(!pq.empty()){
				cc-=pq.top();
				ic++;
				oc--;
				pq.pop();
				d=min(d,COST);
			}
		}
	}
}

int main(){
	int n=read();
	F(i,1,n)t[i]=read();
	F(i,1,n)h[i]=read();
	D(_,n-1){
		int u=read(),v=read();
		es[u].push_back(v);
		es[v].push_back(u);
	}
	dfs(1);
	LL ans=dp[1][0];
	printf("%lld\n",ans);
	return 0;
}