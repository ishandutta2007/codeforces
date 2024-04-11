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

const int MX=1001, MOD=1e9+7;
int n, l, k;
string s;
char gr[MX][MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>l>>k;
    cin>>s;
    sort(s.begin(), s.end());
    int c=0, b=0;
    RE(i,n) RE(j,l) gr[i][j] = ' ';
    RE(j,l) {
    	REP(i,b,k)
    		gr[i][j] = s[c++];
    	REV(i,b,k-1) if(gr[i][j] != gr[k-1][j]) {
    		b = i+1;
    		break;
    	}
    }
    RE(i,n) RE(j,l) {
    	if(gr[i][j] == ' ') gr[i][j] = s[c++];
    }
    RE(i,n) {
    	RE(j,l) cout<<gr[i][j]; cout<<endl;
    }
}