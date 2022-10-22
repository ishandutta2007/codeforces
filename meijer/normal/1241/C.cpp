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

const int MX=2e5;
ll q, n, p[MX], x, a, y, b, k;

ll gcd(ll i, ll j) {return j==0?i:gcd(j,i%j);}
ll lcm(ll i, ll j) {return i * (j/gcd(i,j));}
bool pos(ll tickets) {
    ll mxMoney=0;
    ll both = tickets/lcm(a, b);
    ll fir  = tickets/a - both;
    ll sec  = tickets/b - both;
    ll j=0;
    RE(i,both) mxMoney += p[j++]*(x+y);
    RE(i,fir) mxMoney  += p[j++]*x;
    RE(i,sec) mxMoney  += p[j++]*y;
    return mxMoney >= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>q;
    while(q--) {
        cin>>n;
        RE(i,n) cin>>p[i], p[i]/=100;
        sort(p, p+n, greater<int>());
        cin>>x>>a>>y>>b>>k;
        if(x < y) swap(x, y), swap(a, b);

        ll lb=0, ub=n;
        while(lb != ub) {
            ll mid=(lb+ub)/2;
            if(pos(mid)) ub = mid;
            else lb = mid+1;
        }
        if(!pos(lb)) cout<<-1<<endl;
        else cout<<lb<<endl;
    }
}