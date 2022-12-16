#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int MOD=998244353;
int add(int a,int b){return a+b<MOD?a+b:a+b-MOD;}
void dadd(int &a,int b){a=add(a,b);}
int sub(int a,int b){return a>=b?a-b:a-b+MOD;}
void dsub(int &a,int b){a=sub(a,b);}
int mul(int a,int b){return (LL)a*b%MOD;}
void dmul(int &a,int b){a=mul(a,b);}
const int I2=(MOD+1)/2;

const int N=333;

V es[N];
V ch[N];
void dfs1(int x,int fa){
	D(i,es[x].size()){
		int v=es[x][i];
		if(v==fa)continue;
		ch[x].push_back(v);
		dfs1(v,x);
	}
}

int qwq(int a,int b){
	if(a>b)swap(a,b);
	return a<=-b?a:b;
}

int r;
int f(int x){
	return x<=0?x:r+2-x;
}

int h[N];
int qaq[N][2*N];
void dfs2(int x){
	// cerr<<"dfs2 "<<r<<" "<<x<<endl;
	memset(qaq[x],0,sizeof(qaq[x]));
	qaq[x][f(0)+N]=I2;
	qaq[x][f(r+1)+N]=I2;
	h[x]=0;
	D(i,ch[x].size()){
		int v=ch[x][i];
		dfs2(v);
		int tmp[2*N]={0};
		F(ia,-h[x],h[x]+1)F(ib,-h[v],h[v]+1){
			// if(qaq[x][ia+N]&&qaq[v][ib+N]){
			// 	cerr<<f(ia)<<" / "<<f(ib)<<" -> "<<qwq(f(ia),f(ib))<<endl;
			// }
			dadd(
				tmp[f(qwq(f(ia),f(ib)-1))+N],
				mul(
					qaq[x][ia+N],
					qaq[v][ib+N]
				)
			);
		}
		memcpy(qaq[x],tmp,sizeof(tmp)); 
		h[x]=max(h[x],h[v]+1);
	}
	// F(i,-h[x],h[x]+1){
		// if(qaq[x][i+N]){
			// cerr<<"qaq["<<x<<"]: "<<f(i)<<"->"<<qaq[x][i+N]<<endl;
		// }
	// }
	// cerr<<"h["<<x<<"]="<<h[x]<<endl;
}

int p[N];
int main(){
	int n=read();
	D(_,n-1){
		int u=read(),v=read();
		es[u].push_back(v);
		es[v].push_back(u);
	}
	dfs1(1,-1);
	F(i,0,n){
		r=i;
		// cerr<<f(0)<<" "<<f(r+1)<<endl;
		// cerr<<f(0)<<" "<<f(1)<<endl;
		dfs2(1);
		// cerr<<h[1]<<endl;
		F(j,0,r)dadd(p[i],qaq[1][f(j+1)+N]);
		p[i]=sub(1,p[i]);
	}
	F(i,0,n)dsub(p[i],p[i+1]);
	int pn1=1;
	F(i,0,n){
		// cerr<<"p["<<i<<"]="<<p[i]<<endl;
		dsub(pn1,p[i]);
	}
	int ans=sub(0,pn1);
	F(i,0,n)dadd(ans,mul(p[i],i));
	printf("%d\n",ans);
	return 0;
}