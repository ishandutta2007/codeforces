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

const int MX=135;
ll n;
string t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>t;
    ll l=0, r=0, bad=0;
    while(r < n) {
        if(t[l] != t[r]) {
            bad += r-l;
            if(l != 0)
                bad += r-l-1;
            l = r;
        }
        r++;
    }
    if(l != 0)
        bad += r-l-1;
    cout<<(n*(n+1))/2-bad-n<<endl;
}