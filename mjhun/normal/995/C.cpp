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

struct pt {
	ll x,y;int id;
	pt(ll x, ll y):x(x),y(y){}
	pt(){}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	ll n2(){return x*x+y*y;}
	void in(){scanf("%lld%lld",&x,&y);}
};

pt p[100005];
int r[100005];
int n;

bool ok(){
	pt v(0,0);
	fore(i,0,n){
		pt v0=v+p[i],v1=v-p[i];
		if(v0.n2()<v1.n2()){
			r[p[i].id]=1;
			v=v0;
		}
		else {
			r[p[i].id]=-1;
			v=v1;
		}
	}
	return v.n2()<=1500000LL*1500000LL;
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)p[i].in(),p[i].id=i;
	while(random_shuffle(p,p+n),!ok());
	fore(i,0,n)printf("%d%c",r[i]," \n"[i==n-1]);
	return 0;
}