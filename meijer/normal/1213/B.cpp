#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX=150000;

int t, n;
int a[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
        cin>>n;
        REP(i,0,n) cin>>a[i];
        int mn=INF; int ans=0;
        REP(k,0,n) {
            int i=n-k-1;
            mn = min(mn, a[i]);
            if(mn != a[i]) ans++;
        }
        cout<<ans<<endl;
    }
}