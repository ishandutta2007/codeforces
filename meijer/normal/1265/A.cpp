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

const int MX=4e5, MOD=1e9+7;
int t, n;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
    	cin>>s; n=s.size();
    	if(n == 1) {
    		if(s[0] == '?') s[0] = 'a';
    	} else
    	RE(i,n) if(s[i] == '?') {
    		if(i == 0) {
    			if(s[i+1] == 'a') s[i] = 'b';
    			else s[i] = 'a';
    		} else
    		if(i == n-1) {
    			if(s[i-1] == 'a') s[i] = 'b';
    			else s[i] = 'a';
    		} else {
    			if(s[i-1] != 'a' && s[i+1] != 'a') s[i] = 'a';
    			if(s[i-1] != 'b' && s[i+1] != 'b') s[i] = 'b';
    			if(s[i-1] != 'c' && s[i+1] != 'c') s[i] = 'c';
    		}
    	}
    	bool pos=1;
    	RE(i,n-1) if(s[i] == s[i+1]) pos=0;
    	cout<<(pos ? s : "-1")<<endl;
    }
}