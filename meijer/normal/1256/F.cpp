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

const int MX=1e5, MOD=1e9+7;;

int q, n;
string s, t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>q;
    while(q--) {
    	cin>>n>>s>>t;
		map<char, int> cntS, cntT;
    	RE(i,n) cntS[s[i]]++, cntT[t[i]]++;
    	bool pos=1;
    	for(auto it : cntS)
    		if(cntT[it.fi] != it.se)
    			pos = 0;
    	if(!pos) {
    		cout<<"NO"<<endl;
    		continue;
    	}
    	pos = 0;
    	for(auto it : cntS)	if(it.se > 1) {
    		pos = 1;
    		break;
    	}
    	if(pos) {
    		cout<<"YES"<<endl;
    		continue;
    	}
    	int a=0, b=0;
    	RE(l,n) RE(r,l) {
    		a += s[l] > s[r];
    		b += t[l] > t[r];
    	}
    	cout<<((a&1)==(b&1) ? "YES":"NO")<<endl;
    }
}