#include <bits/stdc++.h>

using namespace std;

#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,b) REP(a,0,b)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int MX = 100, MOD=1e9+7;
string s;
int n;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n>>s;
    int ans=0;
    while(1) {
        bool chang=0;
        for(char c='z'; c>='b'; c--) {
            bool changed=0;
            for(int i=s.size()-1; i>=1; i--) {
                if(s[i] == c && s[i] == s[i-1]+1) {
                    s.erase(i, 1);
                    ans++;
                    changed = 1;
                    break;
                }
            }
            RE(i,s.size()-1) {
                if(s[i] == c && s[i] == s[i+1]+1) {
                    s.erase(i, 1);
                    ans++;
                    changed = 1;
                    break;
                }
            }
            if(changed) {
                chang = 1;
                break;
            }
        }
        if(!chang) break;
    }
    cout<<ans<<endl;
    return 0;
}