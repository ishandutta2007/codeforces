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

int n;ll r;
int a[100005];
set<pair<int,int> > s;

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i);
	fore(i,0,n)a[i+1]+=a[i];
	r=1LL<<60;
	int j=0;
	fore(i,0,n){
		int d=sqrtl(r)+5;
		while(j<=i-d)s.erase(mp(a[j],j)),j++;
		for(auto it=s.lower_bound(mp(a[i]-d,-1));it!=s.end()&&it->fst<=a[i]+d;++it){
			r=min(r,1LL*(i-it->snd)*(i-it->snd)+1LL*(a[i]-it->fst)*(a[i]-it->fst));
		}
		s.insert(mp(a[i],i));
	}
	printf("%lld\n",r);
	return 0;
}