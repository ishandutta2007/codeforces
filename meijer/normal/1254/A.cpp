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

const int MX=100, MOD=1e9+7, CHRS='z'-'a'+1;

int T, r, c, k, seeds;
string S[MX];
bitset<MX> seed[MX];
char ans[MX][MX];

char toC(int i) {
	if(i < CHRS) return 'a'+i;
	if(i < 2*CHRS) return 'A'+i-CHRS;
	return '0'+i-CHRS*2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    while(T--) {
    	cin>>r>>c>>k;
    	RE(i,r) cin>>S[i];
    	RE(i,r) RE(j,c) seed[i][j] = (S[i][j]=='R');
    	seeds = 0;
    	RE(i,r) RE(j,c) if(seed[i][j]) seeds++;
    	int sz = seeds/k;
    	int big = seeds-sz*k;
    	int small = k-big;
    	int I=0, j=0, curSz=0;
    	RE(i,r) {
    		while(1) {
    			if(seed[i][j]) curSz++;
    			if(I >= k) I--;
    			ans[i][j] = toC(I);
    			if(I >= small) {
    				if(curSz == sz+1) {
    					curSz = 0;
    					I++;
    				}
    			} else {
    				if(curSz == sz) {
    					curSz = 0;
    					I++;
    				}
    			}
	    		if(i%2 == 0) {
	    			j++;
	    			if(j == c) {
	    				j--;
	    				break;
	    			}
	    		} else {
	    			j--;
	    			if(j == -1) {
	    				j++;
	    				break;
	    			}
	    		}
    		}
    	}
    	RE(i,r) {
    		RE(j,c) cout<<ans[i][j];
    		cout<<endl;
    	}
    }
}