#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define INF 1e18

ll t, x, y;

int main() {
    cin>>t;
    while(t--) {
        cin>>x>>y;
        cout<<(x-y>1?"YES":"NO")<<endl;
    }
}