#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e18
#define pb push_back
#define fi first
#define se second

const int MX=2e5, MOD=1e9+7;
int n, a[MX], total=0;
ll sum[MX], cnt[MX];

ll getSumRegion(int i, int j) {return sum[j+1] - sum[i];}
ll getCntRegion(int i, int j) {return cnt[j+1] - cnt[i];}
ll costCombine(int i, int j) {
	ll mn = INF;
	REP(k,i,j+1)
		mn = min(mn, getCntRegion(i,k-1)*k-getSumRegion(i,k-1) + getSumRegion(k,j)-getCntRegion(k,j)*k);
	return mn;
}
vi factors(int x) {
	vi f;
	for(int i=2; i*i<=x; i++) {
		if(x%i == 0) {
			f.pb(i);
			while(x%i == 0) x/=i;
		}
	}
	if(x > 1) f.pb(x);
	return f;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    RE(i,n) cin>>a[i];
    RE(i,n) total += a[i];
    sum[0] = 0;
    RE(i,n) sum[i+1] = sum[i] + (a[i]?i:0);
    cnt[0] = 0;
    RE(i,n) cnt[i+1] = cnt[i] + a[i];
    ll mnAns = INF;
    vi f = factors(total);
    RE(i,f.size()) {
    	int x=f[i];
    	int b=0, cnt=0;
    	ll curAns = 0;
    	RE(e,n) {
    		if(getCntRegion(b,e) == x) {
    			curAns += costCombine(b,e);
    			b = e+1;
    		}
    	}
    	mnAns = min(mnAns, curAns);
    }
    if(mnAns == INF) mnAns = -1;
    cout<<mnAns<<endl;
}