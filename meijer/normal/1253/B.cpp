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

const int MX=4e5, MOD=1e9+7;
set<int> today;
set<int> inside;
int n, a[MX], d, c[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    RE(i,n) cin>>a[i];
    bool possible=1;
    RE(i,n) c[i] = 0;
    RE(i,n) {
    	c[d]++;
    	if(a[i] > 0) {
    		if(today.count(a[i])) {
    			possible = 0;
    			break;
    		} else {
    			today.insert(a[i]);
    			inside.insert(a[i]);
    		}
    	} else {
    		if(inside.count(-a[i])) {
    			inside.erase(-a[i]);
    			if(inside.empty())
    				d++, today.clear();
    		} else {
    			possible = 0;
    			break;
    		}
    	}
    }
    if(!inside.empty()) possible=0;
    if(possible) {
    	cout<<d<<endl;
    	RE(i,d) cout<<(i==0?"":" ")<<c[i]; cout<<endl;
    } else {
    	cout<<-1<<endl;
    }
}