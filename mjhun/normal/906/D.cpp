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
using namespace std;
typedef long long ll;

int pm(int a, int e, int m){
	int r=1;
	while(e){
		if(e&1)r=(1LL*r*a)%m;
		e>>=1;
		a=(1LL*a*a)%m;
	}
	return r;
}

int po(int a, int e){
	ll r=1;
	while(e){
		e--;
		r*=a;
		if(r>=(1LL<<31))return -1;
	}
	return r;
}

int phi(int n){
	int r=n;
	for(int i=2;i*i<=n;++i){
		if(n%i==0){
			while(n%i==0)n/=i;
			r/=i;r*=i-1;
		}
	}
	if(n>1)r/=n,r*=n-1;
	return r;
}

int f[64];
int x[100005],z[100005],no[100005];
int n,m,k,q;

int doit(int s, int e, int k){
	int m=f[k];
	if(m==1||s==e)return 1;
	int b=doit(s+1,e,k+1),r=pm(x[s],b,m);
	if(z[s]<0||z[s]>=m)r+=m;
	return r;
}

int main(){
	memset(z,-1,sizeof(z));
	scanf("%d%d",&n,&m);
	fore(i,0,n)scanf("%d",x+i);
	int k=0;f[0]=m;
	while(f[k++]>1)f[k]=phi(f[k-1]);
	no[n]=n;
	for(int i=n-1;i>=0;--i){
		no[i]=no[i+1];
		if(x[i]==1)no[i]=i;
	}
	scanf("%d",&q);
	while(q--){
		int s,e;
		scanf("%d%d",&s,&e);s--;e=min(e,no[s]);
		if(s==e){puts(m>1?"1":"0");continue;}
		z[e-1]=x[e-1];
		int k=e-1;
		while(k-1>=s&&z[k]>=0){k--;z[k]=po(x[k],z[k+1]);}
		printf("%d\n",doit(s,e,0)%m);
		fore(i,k,e)z[i]=-1;
	}
	return 0;
}