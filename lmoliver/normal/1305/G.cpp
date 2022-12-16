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

const int N=2.1e5;
const int L=18;
const int X=1<<L;

void dmax(int &a,int b){a=max(a,b);}
struct P{int val,id;};
bool operator<(P a,P b){return a.val<b.val;}
void ins(P a[2],P b){
	if(b.id==-1)return;
	D(i,2){
		if(b.id==a[i].id){
			dmax(a[i].val,b.val);
			return;
		}
	}
	D(i,2)if(a[i]<b)swap(a[i],b);
}
void ins2(P a[2],P b[2]){
	D(i,2)ins(a,b[i]);
}
P q(P a[2],int id){
	return a[id==a[0].id];
}

P sols[X][2];
void qaq(){
	D(i,L){
		int v=1<<i;
		int v2=v<<1;
		for(int j=0;j<X;j+=v2){
			D(k,v)ins2(sols[j+k+v],sols[j+k]);
		}
	}
}

struct U{
	int fa[N];
	int f(int x){return fa[x]?fa[x]=f(fa[x]):x;}
	bool u(int x,int y){
		x=f(x);
		y=f(y);
		if(x==y)return false;
		fa[x]=y;
		return true;
	}
}u;
LL ans=0;

P b[N];
int a[N];
int main(){
	int n=read();
	F(i,1,n)a[i]=read();
	n++;
	while(true){
		V nd;
		F(i,1,n)if(u.f(i)==i)nd.push_back(i);
		if(nd.size()==1)break;
		D(i,X)D(j,2)sols[i][j]={-1,-1};
		F(i,1,n)ins(sols[a[i]],{a[i],u.f(i)});
		qaq();
		F(i,1,n)b[i]={-1,-1};
		F(i,1,n){
			int f=u.f(i);
			P p=q(sols[(X-1)^a[i]],f);
			if(p.id!=-1)b[f]=max(b[f],{p.val+a[i],p.id});
		}
		for(int v:nd){
			// cerr<<"b["<<v<<"]=("<<b[v].val<<","<<b[v].id<<")"<<endl;
			if(b[v].id!=-1){
				if(u.u(v,b[v].id))ans+=b[v].val;
			}
		}
	}
	F(i,1,n)ans-=a[i];
	printf("%lld\n",ans);
	return 0;
}