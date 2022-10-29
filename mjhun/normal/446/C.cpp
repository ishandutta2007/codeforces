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
#define fst frst
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;
#define MOD 1000000009

int f[300015],sf[300015];
int a[300015];
int n,m;
int st[1<<20],lazy[1<<20][2];

void st_init(int k, int s, int e){
	lazy[k][0]=lazy[k][1]=0;
	if(s+1==e){st[k]=a[s];return;}
	int m=(s+e)/2;
	st_init(2*k,s,m);st_init(2*k+1,m,e);
	st[k]=(st[2*k]+st[2*k+1])%MOD;
}
void st_push(int k, int s, int e){
	if(!lazy[k][0]&&!lazy[k][1])return;
	st[k]+=(1LL*(sf[2+e-s]+MOD-sf[2])*lazy[k][0])%MOD;st[k]%=MOD;
	st[k]+=(1LL*(sf[3+e-s]+MOD-sf[3])*lazy[k][1])%MOD;st[k]%=MOD;
	if(s+1<e){
		lazy[2*k][0]+=lazy[k][0];lazy[2*k][0]%=MOD;lazy[2*k][1]+=lazy[k][1];lazy[2*k][1]%=MOD;
		int m=(s+e)/2;
		lazy[2*k+1][0]+=(1LL*f[m-s]*lazy[k][0]+1LL*f[m-s+1]*lazy[k][1])%MOD;lazy[2*k+1][0]%=MOD;
		lazy[2*k+1][1]+=(1LL*f[m-s+1]*lazy[k][0]+1LL*f[m-s+2]*lazy[k][1])%MOD;lazy[2*k+1][1]%=MOD;
	}
	lazy[k][0]=lazy[k][1]=0;
}
void st_upd(int k, int s, int e, int a, int b, int v){
	st_push(k,s,e);
	if(s>=b||e<=a)return;
	if(s>=a&&e<=b){
		lazy[k][0]=f[v];lazy[k][1]=f[v+1];
		st_push(k,s,e);return;
	}
	int m=(s+e)/2;
	st_upd(2*k,s,m,a,b,v);st_upd(2*k+1,m,e,a,b,v+max(m-max(s,a),0));
	st[k]=(st[2*k]+st[2*k+1])%MOD;
}
int st_query(int k, int s, int e, int a, int b){
	if(s>=b||e<=a)return 0;
	st_push(k,s,e);
	if(s>=a&&e<=b)return st[k];
	int m=(s+e)/2;
	return (st_query(2*k,s,m,a,b)+st_query(2*k+1,m,e,a,b))%MOD;
}

int main(){
	f[0]=1;f[1]=0;
	fore(i,2,300015)f[i]=(f[i-2]+f[i-1])%MOD;
	fore(i,1,300015)sf[i]=(sf[i-1]+f[i-1])%MOD;
	scanf("%d%d",&n,&m);
	fore(i,0,n)scanf("%d",a+i);
	st_init(1,0,n);
	while(m--){
		int t,a,b;
		scanf("%d%d%d",&t,&a,&b);a--;
		if(t==1)st_upd(1,0,n,a,b,0);
		else printf("%d\n",st_query(1,0,n,a,b));
	}
	return 0;
}