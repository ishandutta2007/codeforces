#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
#define sz size()

//===================//
//  Added libraries  //
//===================//

//===================//
//end added libraries//
//===================//

void program();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	program();
}


//===================//
//   begin program   //
//===================//

const int MX = 5e5;
int t, n, k, a[MX];
int sm[MX];

int addSeg(int i, int j, int x) {
    sm[i] += x;
    sm[j+1] -= x;
}

void program() {
    cin>>t;
    while(t--) {
        cin>>n>>k;
        RE(i,n) cin>>a[i];
        RE(i,k*2+2) sm[i] = 0;
        RE(i,n/2) {
            int normal = a[i] + a[n-i-1];
            int mn = normal, mx = normal;
            mn = min(mn, a[i]+1);
            mn = min(mn, a[n-i-1]+1);
            mx = max(mx, a[i]+k);
            mx = max(mx, a[n-i-1]+k);
            addSeg(0, mn-1, 2);
            addSeg(mn, normal-1, 1);
            addSeg(normal+1, mx, 1);
            addSeg(mx+1, k*2, 2);
        }
        REP(i,1,k*2+2) sm[i] += sm[i-1];
        int ans = sm[0];
        REP(i,1,k*2+1) ans = min(ans, sm[i]);
        cout<<ans<<endl;
    }
}