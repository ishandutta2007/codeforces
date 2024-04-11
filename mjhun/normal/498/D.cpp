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
using namespace std;
typedef long long ll;

#define M 60

void merge(int* c, int* a, int* b){
	int t[M];
	fore(i,0,M)t[i]=a[i]+b[(i+a[i])%M];
	fore(i,0,M)c[i]=t[i];
}

int st[400005][M];

void st_upd(int k, int s, int e, int p, int v){
	if(s+1==e){
		fore(i,0,M)st[k][i]=1+(i%v==0);
	}
	else {
		int m=(s+e)/2;
		if(p<m)st_upd(2*k,s,m,p,v);
		else st_upd(2*k+1,m,e,p,v);
		merge(st[k],st[2*k],st[2*k+1]);
	}
}
void st_query(int k, int s, int e, int a, int b, int* r){
	if(e<=a||s>=b)return;
	if(s>=a&&e<=b){merge(r,r,st[k]);return;}
	int m=(s+e)/2;
	st_query(2*k,s,m,a,b,r);
	st_query(2*k+1,m,e,a,b,r);
}

int n;

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		int a;
		scanf("%d",&a);
		st_upd(1,0,n,i,a);
	}
	int q;
	scanf("%d",&q);
	while(q--){
		char _s[4];
		int a,b;
		scanf("%s%d%d",_s,&a,&b);
		if(_s[0]=='A'){
			a--;b--;
			int r[M];
			fore(i,0,M)r[i]=0;
			st_query(1,0,n,a,b,r);
			printf("%d\n",r[0]);
		}
		else {
			a--;
			st_upd(1,0,n,a,b);
		}
	}
	return 0;
}