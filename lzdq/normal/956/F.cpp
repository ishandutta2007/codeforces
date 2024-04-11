#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
typedef long long ll;
using namespace std;
typedef bitset<73> Bit;
const int MAXP=13000,MAXT=3e5;
Bit st;
int tot,to[MAXP][10];
ll f[MAXP][10][20];
int cntp,ch[MAXT][2],id[MAXT];
int Acc(Bit a){
	int u=1;
	for(int i=0; i<73; i++){
		int &p=ch[u][a[i]];
		if(!p) p=++cntp;
		u=p;
	}
	return u;
}
int Dfs(Bit a){
	int &u=id[Acc(a)];
	if(u) return u;
	u=++tot;
	for(int i=a._Find_first(); i<10; i++)
		f[u][i][0]=1;
	for(int i=0; i<10; i++){
		Bit b=a<<i|a>>i;
		for(int j=a._Find_first(); j<i; j=a._Find_next(j))
			b.set(i-j);
		to[u][i]=Dfs(b);
	}
	return u;
}
ll Calc(ll n,int k){
	static int d[20];
	for(int i=0; i<20; i++){
		d[i]=n%10;
		n/=10;
	}
	ll res=0;
	int u=1;
	for(int i=19; ~i; i--){
		for(int j=0; j<d[i]; j++)
			res+=f[to[u][j]][k][i];
		u=to[u][d[i]];
	}
	return res;
}
int main(){
	//freopen("in","r",stdin);
	cntp=1;
	st.set(0);
	Dfs(st);
	for(int i=1; i<20; i++)
		for(int u=1; u<=tot; u++)
			for(int k=0; k<10; k++)
				for(int c=0; c<10; c++)
					f[u][k][i]+=f[to[u][c]][k][i-1];
	//printf("tot %d\n",tot); printf("cntp %d\n",cntp);
	int _; scanf("%d",&_);
	while(_--){
		ll l,r;
		int k;
		scanf("%lld%lld%d",&l,&r,&k);
		printf("%lld\n",Calc(r+1,k)-Calc(l,k));
	}
	return 0;
}