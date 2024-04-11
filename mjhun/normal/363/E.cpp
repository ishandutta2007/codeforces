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

#define INF ((1<<30)-1)

pair<int,ll> f(pair<int,ll> a, pair<int,ll> b){
	if(a.fst>b.fst)return a;
	if(a.fst<b.fst)return b;
	return mp(a.fst,a.snd+b.snd);
}

int n,m,r;
int s[512][512];
int l[512],w[512];
int v[512][512];
pair<int,ll> mx[512][512];

int main(){
	scanf("%d%d%d",&n,&m,&r);
	if(r>252){puts("0 0");return 0;}
	fore(i,0,n)fore(j,0,m)scanf("%d",&s[i][j+1]);
	fore(i,0,n)fore(j,0,m)s[i][j+1]+=s[i][j];
	fore(i,0,r+1)while((l[i]+1)*(l[i]+1)+i*i<=r*r)l[i]++;
	fore(i,0,2*r+1){
		w[i]=-1;
		fore(j,0,r+1)if(abs(i-j)<=r)w[i]=max(w[i],l[j]+l[abs(i-j)]);
	}
	fore(i,0,n)fore(j,0,m)v[i][j]=-INF;
	fore(i,r,n-r)fore(j,r,m-r){
		v[i][j]=0;
		fore(k,-r,r+1)v[i][j]+=s[i+k][j+l[abs(k)]+1]-s[i+k][j-l[abs(k)]];
	}
	fore(i,0,n){
		mx[i][0]=mp(-INF,0LL);
		fore(j,0,m)mx[i][j+1]=f(mx[i][j],mp(v[i][j],1LL));
	}
	auto rr=mp(0,0LL);
	fore(i,r,n-r){
		auto pp=mp(-INF,0LL);
		fore(i0,r,i-2*r)pp=f(pp,mx[i0][m]);
		fore(j,r,m-r){
			auto p=pp;
			fore(i0,max(i-2*r,r),min(i+2*r+1,n-r)){
				p=f(p,mx[i0][max(j-w[abs(i0-i)],0)]);
			}
			rr=f(rr,mp(p.fst+v[i][j],p.snd));
		}
	}
	printf("%d %lld\n",rr.fst,rr.snd);
	return 0;
}