#include<bits/stdc++.h>
//#include<atcoder/all>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
//using namespace atcoder;
//using namespace boost::multiprecision;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
const ll mod=998244353;
const ll LINF=1ll<<60;
const int INF=1<<30;
int dx[]={0,1,0,-1,0,1,-1,1,-1};
int dy[]={0,0,1,0,-1,1,-1,-1,1};



int main(){
    int T;cin >> T;
    while(T--){
        int h,w,n;cin >> h >> w >> n;
        string s;cin >> s;
        vector<int> cnt(26, 0);
        int res = n - (h + w);
        for (int i = 0; i < s.length(); i++) {
            cnt[s[i] - 'A']++;
        }
        ll ans = LINF;
        for (int i = 0; i < 26; i++) {
            if(cnt[i] == 0) continue;
            vector<bool> dp(h + 1, 0);
            dp[0] = true;
            for (int j = 0; j < 26; j++) {
                if(i == j) continue;
                for (int k = h; k >= 0; k--) {
                    if(not dp[k]) continue;
                    if(k + cnt[j] <= h) dp[k + cnt[j]] = true;
                }
            }
            for (int j = max(0, h - cnt[i]); j <= h; j++) {
                if(not dp[j]) continue;
                ll S = h - j;
                chmin(ans, S * max(0ll, (cnt[i] - S - res)));
            }
        }
        cout << ans << endl;
    }
    return 0;
}