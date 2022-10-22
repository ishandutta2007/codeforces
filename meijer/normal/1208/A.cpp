#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

int T, a, b, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    REP(i,0,T) {
        cin>>a>>b>>n;
        int ans = 0;
        if((n-1)%3 != 0)
            ans ^= a;
        if((n)%3 != 0)
            ans ^= b;
        cout<<ans<<endl;
    }
}