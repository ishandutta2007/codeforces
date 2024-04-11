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

const int MX=2048, BS=1<<16, MOD=1e9+7;
int n, k, a[16], b[16];
bitset<MX> dp[BS];

void reverseDP(int bs, int x) {
	if(x != 0 && x*k < MX && dp[bs][x*k]) {
		reverseDP(bs, x*k);
		RE(i,n) if(bs & (1<<i)) {
			b[i]++;
		}
	} else {
		RE(i,n) if((bs & (1<<i)) && (x-a[i] >= 0) && dp[bs^(1<<i)][x-a[i]]) {
			reverseDP(bs^(1<<i), x-a[i]);
			return;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    RE(i,n) cin>>a[i];

    int mxBS = (1<<n);
    RE(i,mxBS) dp[i].reset();
    dp[0][0] = 1;
    REP(bs,1,mxBS) {
    	RE(i,n)
    		if((bs & (1<<i)))
    			dp[bs] |= (dp[bs^(1<<i)]<<a[i]);
    	REV(i,1,(MX-1)/k+1) if(dp[bs][i*k]) dp[bs][i] = 1;
    }

    if(dp[(1<<n)-1][1]) {
    	cout<<"YES"<<endl;
    	RE(i,n) b[i] = 0;
    	reverseDP((1<<n)-1,1);
    	priority_queue<ii> pq;
    	RE(i,n) pq.push({b[i], a[i]});
    	while(pq.size() >= 2) {
    		ii p1 = pq.top(); pq.pop();
    		ii p2 = pq.top(); pq.pop();
    		int nb = p1.fi;
    		int na = p1.se + p2.se;
    		cout<<p1.se<<" "<<p2.se<<endl;
    		while(na % k == 0) {
    			na /= k;
    			nb--;
    		}
    		pq.push({nb, na});
    	}
    } else {
    	cout<<"NO"<<endl;
    }
}