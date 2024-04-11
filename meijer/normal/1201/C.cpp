#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e18
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX=2e5;

ll n, k;
ll a[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    REP(i,0,n) cin>>a[i];
    sort(a, a+n);
    ll c=n/2;
    ll e=c+1;
    ll val=a[c];
    while(k > 0) {
        while(e!=n && a[e] == val) e++;
        ll w = e-c;
        ll maxOp = INF;
        if(e != n)
            maxOp = a[e]-val;
        ll op = k/w;
        if(op > maxOp) {
            val += maxOp;
            k -= w*maxOp;
        } else {
            val += op;
            break;
        }
    }
    cout<<val<<endl;
}