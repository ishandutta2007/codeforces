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

const int MX=2e5, MOD=1e9+7;
string s;
int n;
ll mem[MX];

ll getAns(ll i) {
	return (i<0 ? 1 : mem[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s; n=s.size();
    mem[0] = 1;
    REP(i,1,n) {
    	mem[i] = mem[i-1];
    	if(s[i] == 'u' || s[i] == 'n')
	    	if(s[i] == s[i-1])
	    		mem[i] = (getAns(i-1) + getAns(i-2))%MOD;
    }
    RE(i,n) {
    	if(s[i] == 'w' || s[i] == 'm')
    		mem[n-1] = 0;
    }
    cout<<mem[n-1]<<endl;
}