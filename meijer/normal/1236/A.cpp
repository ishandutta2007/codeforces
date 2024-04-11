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

int t, a, b, c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
        cin>>a>>b>>c;
        int ans=0;
        while(b > 0 && c > 1) {
            ans += 3;
            b-=1; c-=2;
        }
        while(a > 0 && b > 1) {
            ans += 3;
            b-=2; a-=1;
        }
        cout<<ans<<endl;
    }
}