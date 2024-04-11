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

const int N=1.1e5;
struct P{LL d;int v;};
bool operator>(P a,P b){return a.d>b.d;}
LL ans[N];
LL dis[N];
bool ok[N];
int u[N],v[N],w[N],aw[N];
struct E{int v,e;};
vector<E> es[N];
int main(){
	int n=read(),m=read(),q=read();
	F(i,1,m){
		u[i]=read();
		v[i]=read();
		w[i]=read();
		aw[i]=w[i];
		es[u[i]].push_back({v[i],i});
	}

	F(i,1,n)dis[i]=1e18;
	priority_queue<P,vector<P>,greater<P>> pq;
	dis[1]=0;
	pq.push({dis[1],1});
	while(!pq.empty()){
		P p=pq.top();
		pq.pop();
		if(dis[p.v]!=p.d)continue;
		for(E e:es[p.v]){
			LL t=p.d+w[e.e];
			if(t<dis[e.v]){
				dis[e.v]=t;
				pq.push({t,e.v});
			}
		}
	}

	F(i,1,n)ans[i]=dis[i];
	F(i,1,n)ok[i]=dis[i]<1e18;

	D(_,q){
		int op=read();
		if(op==1){
			int x=read();
			printf("%lld\n",ok[x]?ans[x]:-1);
		}
		else if(op==2){
			int s=read();
			D(_,s)aw[read()]++;
			F(i,1,m)w[i]=ans[u[i]]-ans[v[i]]+aw[i];
			vector<vector<P>> qaq(s+1);
			F(i,1,n)dis[i]=1e18;
			dis[1]=0;
			qaq[0]={{0,1}};
			F(i,0,s){
				while(!qaq[i].empty()){
					P p=qaq[i].back();
					qaq[i].pop_back();
					if(p.d!=dis[p.v])continue;
					for(E e:es[p.v]){
						LL t=p.d+w[e.e];
						if(t<=s&&t<dis[e.v]){
							dis[e.v]=t;
							qaq[t].push_back({t,e.v});
						}
					}
				}
			}
			F(i,1,n)ans[i]+=dis[i];
		}
		else abort();
	}
	return 0;
}