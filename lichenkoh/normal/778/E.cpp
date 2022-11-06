#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18+5;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll mn=1004;
char A[mn];
ll n;
char B[mn][mn];
ll Blen[mn];
ll gc[10];
long long dp[mn][mn][2];
ll old_to_actual_idx[mn],actual_to_new_idx[mn];
vll resort(vll sorted, ll x) {
	vector<ll> sort_tmp[10];
	for (auto &actual_idx:sorted) {
		sort_tmp[(ll)B[actual_idx][x]].PB(actual_idx);
	}
	vector<ll> new_sorted;
	for (ll d=9;d>=0;d--) {
		for (auto &actual_idx:sort_tmp[d]) new_sorted.PB(actual_idx);
	}
	return new_sorted;
}
ll Alen;
ll cost(ll actual_idx, ll x, ll digit) {
	if (x>=max(Alen,Blen[actual_idx])&&digit==0) return 0;
	else return gc[digit];
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll m=0;
	scanf("%s\n",A);
	{
		ll len=strlen(A);
		Alen=len;
		reverse(A,A+len);
		for (ll j=0;j<len;j++) {
			if (A[j]!='?') {
				A[j]-='0';
			}
		}
		chkmax(m,len);
	}
	scanf("%lld\n",&n);
	for (ll i=0;i<n;i++) {
		scanf("%s\n",B[i]);
		ll len=strlen(B[i]);
		Blen[i]=len;
		reverse(B[i],B[i]+len);
		for (ll j=0;j<len;j++) B[i][j]-='0';
		chkmax(m,len);
	}
	++m;
	vll sorted;
	for (ll i=0;i<n;i++) sorted.PB(i);
	for (ll i=0;i<10;i++) scanf("%lld",&gc[i]);

	memset(dp,-1,sizeof dp);
	dp[0][0][0]=0;
	for (ll x=0;x<m;x++) {
		vll new_sorted=resort(sorted,x);
		for (ll old_idx=0;old_idx<n;old_idx++) {
			ll actual_idx=sorted[old_idx];
			old_to_actual_idx[old_idx]=actual_idx;
		}
		for (ll new_idx=0;new_idx<n;new_idx++) {
			ll actual_idx=new_sorted[new_idx];
			actual_to_new_idx[actual_idx]=new_idx;
		}
		for (ll d=0;d<10;d++) {
			if (A[x]!='?'&&A[x]!=d) continue;
			ll dest_new_idx=0;
			long long add_sum=0;
			for (ll actual_idx=0;actual_idx<n;actual_idx++) {
				ll Bdigit=B[actual_idx][x];
				add_sum+=cost(actual_idx,x,(d+Bdigit)%10);
				if (d+Bdigit>=10) {
					ll new_idx = actual_to_new_idx[actual_idx];
					chkmax(dest_new_idx, new_idx+1);
				}
			}
			//printf("add_sum_init for d:%lld x:%lld. add_sum:%lld. dest_new_idx:%lld\n",d,x,add_sum,dest_new_idx);
			for (ll old_idx=0;old_idx<=n;old_idx++) {
				for (ll nonzero=0;nonzero<2;nonzero++) {
					long long old_sum=dp[x][old_idx][nonzero];
					if (old_sum!=-1) {
						ll new_nonzero=0;
						if (x>=Alen) new_nonzero=nonzero;
						if (d>0) new_nonzero=1;
						chkmax(dp[x+1][dest_new_idx][new_nonzero], old_sum+add_sum);
						//printf("UPD x:%lld d:%lld old_idx:%lld dest_new_idx:%lld. onz:%lld->%lld. %lld+%lld=%lld\n",x,d,old_idx,dest_new_idx,nonzero,new_nonzero,old_sum,add_sum,old_sum+add_sum);
					}
				}
				if (old_idx==n) break;
				ll actual_idx=old_to_actual_idx[old_idx];
				ll new_idx = actual_to_new_idx[actual_idx];
				ll Bdigit=B[actual_idx][x];
				if (d+Bdigit+1>=10) {
					chkmax(dest_new_idx, new_idx+1);
				}
				add_sum+=cost(actual_idx,x,(d+Bdigit+1)%10)-cost(actual_idx,x,(d+Bdigit)%10);
				//printf("x:%lld d:%lld actual_idx:%lld newd:%lld oldd:%lld. dest_new_idx:%lld d:%lld Bdigit:%lld\n",x,d,actual_idx,c[(d+Bdigit+1)%10],c[(d+Bdigit)%10],dest_new_idx,d,Bdigit);
			}
		}
		swap(sorted,new_sorted);
	}
	long long final=-INF;
	for (ll x=0;x<=n;x++) {
		chkmax(final,dp[m][x][1]);
	}
	printf("%lld\n",final);
}