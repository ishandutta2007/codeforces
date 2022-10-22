#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=1e5;
int t, a, b, c, n;
string s, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
    	cin>>n>>a>>b>>c>>s;
    	ans.resize(n);
    	int wins=0;
    	RE(i,n) {
    		ans[i] = '.';
    		if(s[i] == 'S' && a > 0) a--, wins++, ans[i] = 'R';
    		if(s[i] == 'R' && b > 0) b--, wins++, ans[i] = 'P';
    		if(s[i] == 'P' && c > 0) c--, wins++, ans[i] = 'S';
    	}
    	RE(i,n) if(ans[i] == '.') {
    		if(a) {a--; ans[i] = 'R'; continue;}
    		if(b) {b--; ans[i] = 'P'; continue;}
    		if(c) {c--; ans[i] = 'S'; continue;}
    	}
    	if(wins >= (n/2 + int(n%2))) {
    		cout<<"YES"<<endl;
    		cout<<ans<<endl;
    	} else {
    		cout<<"NO"<<endl;
    	}
    }
}