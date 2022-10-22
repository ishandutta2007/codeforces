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
int k[3], a[3][MX], n;
int cnt[3][MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    RE(i,3) cin>>k[i];
    n = k[0]+k[1]+k[2];
    RE(i,3) RE(j,k[i])
    	cin>>a[i][j];
    RE(i,3) RE(j,k[i]) {
    	cnt[i][a[i][j]]++;
    }
    RE(i,3) REP(j,1,n+1) {
    	cnt[i][j] += cnt[i][j-1];
    }
    int minAns = n, minLCost = cnt[1][0] - cnt[0][0];
    REP(r,0,n+1) {
    	int ans = n - k[2] - cnt[1][r] + cnt[2][r];
    	minLCost = min(minLCost, cnt[1][r] - cnt[0][r]);
    	ans += minLCost;
    	minAns = min(minAns, ans);
    }
    cout<<minAns<<endl;
}