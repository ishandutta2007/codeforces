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
#define SZ(x) ((int)x.size())
#define MOD 1000000007
using namespace std;
typedef long long ll;

int pm(int a, int e){
 	int r=1;
 	while(e){
 		if(e&1)r=(1LL*r*a)%MOD;
 		e>>=1;
 		a=(1LL*a*a)%MOD;
 	}
 	return r;
}

int f[100005],fi[100005];

int c(int n, int k){
	if(k<0||k>n)return 0;
	return 1LL*f[n]*fi[k]%MOD*fi[n-k]%MOD;
}

vector<int> p[100005];

int main(){
	f[0]=fi[0]=1;
	fore(i,1,100005)f[i]=(1LL*f[i-1]*i)%MOD,fi[i]=pm(f[i],MOD-2);
	fore(i,2,100005)if(!SZ(p[i]))for(int j=i;j<100005;j+=i)p[j].pb(i);
	int q;
	scanf("%d",&q);
	while(q--){
		int n,f;
		scanf("%d%d",&n,&f);
		int r=0;
		fore(m,0,1<<SZ(p[n])){
			int d=1,q=0;
			fore(i,0,SZ(p[n]))if(m&(1<<i))d*=p[n][i],q^=1;
			int a=c(n/d-1,f-1);
			if(q)r+=MOD-a;
			else r+=a;
			r%=MOD;
		}
		printf("%d\n",r);
	}
	return 0;
}