#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,n) for(int i=1;i<=n;i++)

#define N_ 200100
int TC, n, m;
long long T, K;

int w[N_], P[N_];

bool Pos(int A){
	int i, c = 0;
	int t = P[A];
	long long ss = 0, prv = 0;
	for(i=1;i<=n;i++){
		if(w[i] <= t){
			ss+=w[i];
			c++;
		}
		if(c == A){
			if(ss <= T){
				K = t;
				return true;
			}
			return false;
		}
		if(w[i] <= t && c % m == 0){
			ss += (ss-prv);
			prv = ss;
		}
	}
	return false;
}

void Solve(){
	int i;
	scanf("%d%d%lld",&n,&m,&T);
	for(i=1;i<=n;i++){
		scanf("%d",&w[i]);
		P[i]=w[i];
	}
	sort(P+1,P+n+1);
	int b = 1, e = n, mid, r = 0;
	K = 1;
	while(b<=e){
		mid = (b+e)>>1;
		if(Pos(mid)){
			r = mid;
			b = mid + 1;
		}
		else e = mid - 1;
	}
	printf("%d %lld\n",r,K);
}

int main(){
	scanf("%d",&TC);
	while(TC--){
		Solve();
	}
}