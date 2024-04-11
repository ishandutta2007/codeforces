#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(ll a=ll(b); a<ll(c); ++a)
#define REV(a,b,c) for(ll a=ll(c); a>=ll(b); --a)
#define INF 1e18
#define fi first
#define se second

const ll MX=1e6;

ll n, a[MX], cnt[MX], psum[MX], A=0, mxless[MX];

pair<ii, ii> push_pair(pair<ii, ii> mx, ii val) {
    return {max(mx.fi, val), max(mx.se, min(mx.fi, val))};
}

int main() {
    cin>>n;
    REP(i,0,n) cin>>a[i], A=max(A,a[i])+1LL;
    REP(i,0,A+10LL) cnt[i]=0;
    REP(i,0,n) cnt[a[i]]++;
    psum[0] = 0;
    REP(i,0,A) psum[i+1LL] = psum[i]+cnt[i];
    REP(i,0,A) mxless[i] = -1LL;
    REP(i,0,A) {
        if(i != 0LL) mxless[i] = mxless[i-1LL];
        if(cnt[i] != 0LL) mxless[i] = i;
    }

    ll ans=0;
    REP(y,2,A) {
        ll cntY=0;
        for(ll i=0; i*y<A; i++)
            cntY += i*ll(psum[min(A, (i+1LL)*y)]-psum[i*y]);

        ll lb=((A-1LL)/y)*y, ub=A;
        pair<ii, ii> mx({-1LL,-1LL}, {-1LL,-1LL});
        while(lb >= 0LL) {
            ll countMore = (mx.fi.fi >= 0LL) + (mx.se.fi >= 0LL);
            ll prv = mxless[ub-1LL];
            if(prv >= lb) {
                mx = push_pair(mx, ii{prv%y, prv});
                if(cnt[prv] == 1LL)
                    prv = mxless[prv-1LL];
                if(prv >= lb)
                    mx = push_pair(mx, ii{prv%y, prv});
            }

            //calculate same log
            if(mx.fi.fi != -1LL) {
                ll x = (lb + mx.fi.fi)/2LL;
                x = min(x, cntY - lb/y);
                if(x >= 2LL && x*y > ans) ans = x*y;
            }
            //calculate different log
            if(mx.se.fi != -1LL) {
                ll x = lb + mx.se.fi;
                x = min(x, cntY - 2LL*(lb/y));
                if(x >= 2LL && x*y > ans) ans = x*y;

                if(countMore + (mx.fi.se < ub) >= 2LL) {
                    x = lb + mx.fi.fi;
                    x = min(x, cntY - 2LL*(lb/y) - 1LL);
                    if(x >= 2LL && x*y > ans) ans = x*y;
                }
            }

            ub = lb;
            lb -= y;
        }
    }
    cout<<ans<<endl;
}