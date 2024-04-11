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

int n,tt;
int a[1<<18],t[1<<18];
vector<pair<int,int> > v;
ll s0,s1;

int main(){
	scanf("%d%d",&n,&tt);
	fore(i,0,n)scanf("%d",a+i);
	fore(i,0,n)scanf("%d",t+i);
	fore(i,0,n)v.pb(mp(t[i],a[i]));
	sort(v.begin(),v.end());
	fore(i,0,n)t[i]=v[i].fst,a[i]=v[i].snd;
	if(tt<t[0]||tt>t[n-1]){puts("0");return 0;}
	fore(i,0,n)s0+=1LL*a[i]*t[i],s1+=a[i];
	if(s0==s1*tt){printf("%lld\n",s1);return 0;}
	if(s0>s1*tt){ // alta
		for(int i=n-1;i>=0;--i){
			if(s0-1LL*a[i]*t[i]>(s1-a[i])*tt){
				s0-=1LL*a[i]*t[i];
				s1-=a[i];
			}
			else {
				printf("%.12lf\n",s1-(1.*tt*s1-s0)/(tt-t[i]));
				return 0;
			}
		}
		assert(0);
	}
	else { // baja
		fore(i,0,n){
			if(s0-1LL*a[i]*t[i]<(s1-a[i])*tt){
				s0-=1LL*a[i]*t[i];
				s1-=a[i];
			}
			else {
				printf("%.12lf\n",s1-(1.*tt*s1-s0)/(tt-t[i]));
				return 0;
			}
		}
		assert(0);
	}
	return 0;
}