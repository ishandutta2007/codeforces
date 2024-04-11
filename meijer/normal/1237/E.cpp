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

const ll MX=2e6, MOD=998244353;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    int x=1;
    while(x <= n) {
        if(n == x || n == x+1) {
            cout<<1<<endl;
            return 0;
        }
        if(x % 2) {
            x = x + 1 + x + 1;
        } else {
            x = x + x + 1;
        }
    }
    cout<<0<<endl;
}