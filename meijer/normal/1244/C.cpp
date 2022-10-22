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
ll n, p, d, w;

ll gcd(ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
ll lcm(ll a, ll b) {return a * (b/gcd(a,b));}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>p>>w>>d;
    ll l = gcd(w, d);
    if(p % l != 0) {
        cout<<-1<<endl;
        return 0;
    } else {
        ll i=0, sum=p%w;
        while(sum <= p) {
            if(sum % d == 0) {
                ll x = p/w - i;
                ll y = sum/d;
                ll z = n - x - y;
                if(z < 0) {
                    cout<<-1<<endl;
                    return 0;
                }
                cout<<x<<" "<<y<<" "<<z<<endl;
                return 0;
            }
            sum += w; i++;
        }
        cout<<-1<<endl;
        return 0;
    }
}