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
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=5e5, MOD=1e9+7;
int t, n, p[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
 	while(t--) {
 		cin>>n;
 		RE(i,n) cin>>p[i];
 		int g=n, s, b;
 		RE(i,n-1) {
 			if(p[i] != p[i+1]) {
 				g = i+1;
 				break;
 			}
 		}
 		s = b = g;
 		REP(i,s,n-g-1) {
 			int j = i+g;
 			if(p[j] != p[j+1]) {
 				s = i+1;
 				break;
 			}
 		}
 		REP(i,b,n-g-s-1) {
 			int j = i+g+s;
 			if(p[j] != p[j+1] && g+s+i+1 <= n/2) {
 				b = i+1;
 			}
 		}
 		if(g + s + b > n/2 || g >= s || g >= b)
 			g = s = b = 0;
 		cout<<g<<" "<<s<<" "<<b<<endl;
 	}
}