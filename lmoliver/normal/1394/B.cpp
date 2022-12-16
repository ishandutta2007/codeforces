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

struct E{
	int v,w;
};
bool operator<(E a,E b){return a.w<b.w;}
const int N=200200;
vector<E> es[N];
const int K=12;
bool ban[K*K][K*K];
V ins[N];
int main(){
	int n=read(),m=read();
	int k=read();
	F(i,1,m){
		int u=read(),v=read(),w=read();
		es[u].push_back({v,w});
	}
	F(i,1,n)sort(es[i].begin(),es[i].end());
	F(i,1,n){
		int s=es[i].size();
		D(j,s){
			int v=es[i][j].v;
			ins[v].push_back(s*K+j+1);
		}
	}
	F(i,1,n){
		int s=ins[i].size();
		map<int,int> mp;
		D(j,s)mp[ins[i][j]]++;
		for(auto p1:mp)for(auto p2:mp){
			if(p1.first!=p2.first||p1.second>=2){
				ban[p1.first][p2.first]=true;
			}
		}
	}
	int a[K];
	int ans=0;
#define C(X) for(a[X]=1;a[X]<=(X<=k?X:1);a[X]++)
	C(1)C(2)C(3)C(4)C(5)C(6)C(7)C(8)C(9){
		F(i,1,9)F(j,1,9)if(ban[i*K+a[i]][j*K+a[j]])goto qaq;
		ans++;
		qaq:;
	}
	printf("%d\n",ans);
	return 0;
}