#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
#define MOD 1000000007
#define int long long
using namespace std;
typedef long long ll;

int pm(int a, int e){
	int r=1;
	while(e){
		if(e&1)r=1LL*r*a%MOD;
		e>>=1;
		a=1LL*a*a%MOD;
	}
	return r;
}

int n,m,kk,k,s;
pair<int,int> x[2048];
int fa[200005];
int ifa[200005];
int g[2048],f[32][2048];

int c(int n, int k){return 1LL*fa[n]*ifa[k]%MOD*ifa[n-k]%MOD;}

main(){
	fa[0]=1;
	fore(i,1,200005)fa[i]=1LL*fa[i-1]*i%MOD;
	fore(i,0,200005)ifa[i]=pm(fa[i],MOD-2);
	scanf("%lld%lld%lld%lld",&n,&m,&kk,&s);
	fore(i,0,kk){
		int a,b;
		scanf("%lld%lld",&a,&b);a--;b--;
		if(a==0&&b==0||a==n-1&&b==m-1){s=(s+1)/2;continue;}
		x[k++]=mp(a,b);
	}
	x[k++]=mp(0,0);
	sort(x,x+k);
	for(int i=k-1;i>=0;--i){
		g[i]=c(n-1-x[i].fst+m-1-x[i].snd,n-1-x[i].fst);
		fore(j,i+1,k)if(x[j].fst>=x[i].fst&&x[j].snd>=x[i].snd){
			g[i]+=MOD-1LL*c(x[j].fst-x[i].fst+x[j].snd-x[i].snd,x[j].fst-x[i].fst)*g[j]%MOD;g[i]%=MOD;
		}
	}
	mcpy(f[0],g);
	fore(_,1,22){
		for(int i=k-1;i>=0;--i){
			f[_][i]=c(n-1-x[i].fst+m-1-x[i].snd,n-1-x[i].fst);
			fore(j,i+1,k)if(x[j].fst>=x[i].fst&&x[j].snd>=x[i].snd){
				f[_][i]+=MOD-1LL*c(x[j].fst-x[i].fst+x[j].snd-x[i].snd,x[j].fst-x[i].fst)*f[_][j]%MOD;
				f[_][i]%=MOD;
			}
			fore(j,0,_)f[_][i]+=MOD-f[j][i],f[_][i]%=MOD;
		}
	}
	int t=0,r=0;
	fore(i,0,22)t+=f[i][0],t%=MOD,r+=1LL*f[i][0]*s%MOD,r%=MOD,s=(s+1)/2;
	int a=c(n-1+m-1,m-1);
	r+=(a+MOD-t)%MOD;r%=MOD;
	printf("%lld\n",1LL*r*pm(a,MOD-2)%MOD);
	return 0;
}