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
#define mset(x,a) (memset((x),(a),sizeof(x)))
#define mcpy(x,y) (memcpy((x),(y),sizeof(x)))
using namespace std;
typedef long long ll;

pair<ll,int> x[100005],y[100005];
int n,k;
bool h[100005];
int q;

void asd(int i){
	if(!h[i])q++;
	h[i]=true;
}
void qwe(int i){
	h[i]=false;
}

bool can(int i0, int i1, int j0, int j1){
	q=0;
	fore(i,0,i0)asd(x[i].snd);
	fore(i,n-i1,n)asd(x[i].snd);
	fore(i,0,j0)asd(y[i].snd);
	fore(i,n-j1,n)asd(y[i].snd);
	fore(i,0,i0)qwe(x[i].snd);
	fore(i,n-i1,n)qwe(x[i].snd);
	fore(i,0,j0)qwe(y[i].snd);
	fore(i,n-j1,n)qwe(y[i].snd);
	return q<=k;
}

int main(){
	scanf("%d%d",&n,&k);
	fore(i,0,n){
		ll x1,y1,x2,y2;
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		ll xx=x1+x2,yy=y1+y2;
		x[i]=mp(xx,i);
		y[i]=mp(yy,i);
	}
	sort(x,x+n);sort(y,y+n);
	ll r=1LL<<62;
	fore(i0,0,k+1)fore(i1,0,k-i0+1){
		fore(j0,0,k+1)fore(j1,0,k-j0+1){
			if(can(i0,i1,j0,j1)){
				r=min(r,max((x[n-1-i1].fst-x[i0].fst+1)/2,1LL)*max((y[n-1-j1].fst-y[j0].fst+1)/2,1LL));
			}
		}	
	}
	printf("%lld\n",r);
	return 0;
}