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

const int N=5.1e5;
struct E{
	int v,w;
};
vector<E> es[N];

int k;
LL dp[N][2];
void dfs(int x,int fa){
	for(E e:es[x])if(e.v!=fa){
		dfs(e.v,x);
	}
	D(u,2){
		LL &d=dp[x][u];
		d=0;
		int kk=k-u;
		priority_queue<LL> ss;
		for(E e:es[x])if(e.v!=fa){
			d+=dp[e.v][0];
			ss.push(e.w+dp[e.v][1]-dp[e.v][0]);
		}
		while(kk>0&&!ss.empty()&&ss.top()>0){
			kk--;
			d+=ss.top();
			ss.pop();
		}
	}
}

int main(){
	int q=read();
	D(_,q){
		int n=read();
		k=read();
		D(_,n-1){
			int u=read(),v=read(),w=read();
			es[u].push_back({v,w});
			es[v].push_back({u,w});
		}
		dfs(1,-1);
		printf("%lld\n",dp[1][0]);
		F(i,1,n)es[i].clear();
	}
	return 0;
}