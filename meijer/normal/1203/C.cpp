#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX = 5e5;

ll n;
ll a[MX];

ll gcd(ll a, ll b) {return b==0?a:gcd(b,a%b);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    REP(i,0,n) cin>>a[i];
    ll GCD=a[0];
    REP(i,1,n) GCD = gcd(GCD, a[i]);
    ll i=1;
    ll ans=0;
    while(i*i <= GCD) {
        if(GCD%i == 0) ans+=2;
        if(i*i == GCD) ans--;
        i++;
    }
    cout<<ans<<endl;
}