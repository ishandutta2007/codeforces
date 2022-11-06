#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=100000+8;
ld a[MAXN],b[MAXN];
ld ans[2][MAXN];
pair<ld,ld> solve(ld sum, ld prod) {
	ld a=1; ld b=-sum; ld c=prod;
	ld sqr=sqrt(max(0.0l,b*b-4*a*c));
	ld x =(-b+sqr)/(2*a);
	ld y=sum-x;
	//printf("%f %f: %f %f\n",(double)sum,(double)prod,(double)x,(double)y);
	return MP(x,y);
}
int main() {
	ll n; scanf("%d",&n);
	for (ll i=0;i<n;i++) {
		double tmp;
		scanf("%lf",&tmp);
		a[i]=tmp;
	}
	for (ll i=0;i<n;i++) {
		double tmp;
		scanf("%lf",&tmp);
		b[i]=tmp;
	}
	for (ll i=1;i<n;i++) {
		a[i]+=a[i-1];
	}
	b[n]=0;
	for (ll i=n-2;i>=0;i--) {
		b[i]+=b[i+1];
	}
	for (ll i=0;i<n;i++) {
		ld top=a[i];
		ld bot=b[i+1];
		ld prod=top;
		ld sum=1-bot+prod;
		pair<ld,ld> res=solve(sum,prod);
		//printf("%f %f %f %f %f %f\n",top,bot,prod,sum,res.first,res.second);
		ans[0][i]=res.first;
		ans[1][i]=res.second;
		/*if (i>0) {
			bool sw=false;
			for (ll t=0;t<2;t++) {
				sw=sw||(ans[t][i-1]>ans[t][i]);
			}
			if (sw) {
				swap(ans[0][i],ans[1][i]);
			}
		}
		for (ll t=0;t<2;t++) {
			ld prev=0;
			if (i>0) prev=ans[t][i-1];
			if (!(ans[t][i]-prev>=-1e-16) && i>0) {
				printf("Wrong iteration: %d. %f %f. %f %f.\n",i,(double)ans[0][i-1],(double)ans[1][i-1],(double)res.first,(double)res.second);
			}
			assert(ans[t][i]-prev>=-1e-16);
		}*/
	}
	for (ll t=0;t<2;t++) {
		for (ll x=0;x<n;x++) {
			ld final=ans[t][x];
			if (x>0) final-=ans[t][x-1];
			final=max(0.0l,final);
			printf("%.8f ",(double)final);
		}
		printf("\n");
	}
}