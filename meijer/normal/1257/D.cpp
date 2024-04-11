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
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=3e5, MOD=1e9+7;
int t, n, a[MX], m, p[MX], s[MX];
int SEG[MX*4], SA[MX];
map<int, int> maxP;

void buildSeg(int p=0, int l=0, int r=n-1) {
	if(l == r) {
		SEG[p] = a[l];
	} else {
		int m=(l+r)/2;
		buildSeg(p*2+1,l,m);
		buildSeg(p*2+2,m+1,r);
		SEG[p] = max(SEG[p*2+1], SEG[p*2+2]);
	}
}
int getMax(int i, int j, int p=0, int l=0, int r=n-1) {
	if(i > r || j < l) return 0;
	if(i <= l && j >= r) return SEG[p];
	int m=(l+r)/2;
	int a=getMax(i,j,p*2+1,l,m);
	int b=getMax(i,j,p*2+2,m+1,r);
	return max(a,b);
}
int getMaxP(int S) {
	if(maxP.lower_bound(S) == maxP.end())
		return 0;
	return maxP.lower_bound(S)->se;
}
bool possible(int b, int e) {
	return getMax(b, e) <= getMaxP(e-b+1);
}
int minDays(int b) {
	if(b == n) return 0;

	int lb=b, ub=n-1;
	while(lb != ub) {
		int mid=(lb+ub+1)/2;
		if(possible(b,mid)) lb = mid;
		else ub = mid-1;
	}

	if(!possible(b,lb))
		return -1;
	int ans = minDays(lb+1) + 1;
	return ans == 0 ? -1 : ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
    	cin>>n;
    	RE(i,n) cin>>a[i];
    	cin>>m;
    	RE(i,m) cin>>p[i]>>s[i];
    	RE(i,m) SA[i] = i;
    	sort(SA, SA+m, [](int i, int j) {
    		return s[i] > s[j];
    	});

    	maxP.clear();
    	int mx = 0;
    	RE(i,m) {
    		mx = max(mx, p[SA[i]]);
    		maxP[s[SA[i]]] = mx;
    	}

    	buildSeg();

    	cout<<minDays(0)<<endl;
    }
}