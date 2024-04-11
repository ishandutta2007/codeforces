#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second
#define len(v) (v).size()
#define INF 1000000005
#define ll long long

using namespace std;

typedef pair<int,int>P;
typedef vector<ll>vl;

class BIT {
private:
    int n;
    vector<ll> bit;
public:
    BIT(int sz){ n = sz + 1, bit.resize(n, 0); }
    void add(int i, ll x){
        i++;
        while(i < n) bit[i] += x, i += i & -i;
    }
    ll sum(int i){
        i++;
        ll s = 0;
        while(i > 0) s += bit[i], i -= i & -i;
        return s;
    }
    int upper_bound(ll x){
        int b = 1;
        while(b < n-1) b *= 2;
        int a = 0;
        while(b > 0){
            if(a+b <= n-1 && x >= bit[a+b]){
                x -= bit[a+b];
                a += b;
            }
            b >>= 1;
        }
        return (a < n-1) ? a : -1;
    }
    int lower_bound(ll x){
        return upper_bound(x-1);
    }
    void print(){
        rep(i,n-1){
            cout << sum(i) - sum(i-1) << " ";
        }
        cout << "\n";
    }
};

const int MAX_N = 1000005;

vector<P> que[MAX_N];

int main()
{
    int n,K,m;
    cin >> n >> K >> m;
    vl l(m), r(m), c(m), p(m);
    vector<P> vec(m);
    rep(i,m){
        cin >> l[i] >> r[i] >> c[i] >> p[i];
        --l[i];
        vec[i] = P(p[i], i);
        que[l[i]].pb(P(1,i)), que[r[i]].pb(P(-1,i));
    }
    BIT cnt(m), sm(m);
    sort(all(vec));
    ll ans = 0, pre = 0;
    rep(i,n){
        if(len(que[i])){
            sort(all(que[i]));
            for(auto& pp : que[i]){
                if(pp.fi < 0){
                    int id = lower_bound(all(vec),P(p[pp.se], pp.se)) - vec.begin();
                    cnt.add(id, -c[pp.se]);
                    sm.add(id, -c[pp.se]*p[pp.se]);
                }else{
                    int id = lower_bound(all(vec),P(p[pp.se], pp.se)) - vec.begin();
                    cnt.add(id, c[pp.se]);
                    sm.add(id, c[pp.se]*p[pp.se]);
                }
            }
            int id = cnt.lower_bound(K);
            if(id == -1){
                pre = sm.sum(m-1);
            }else{
                ll al = cnt.sum(id);
                pre = sm.sum(id) - (al-K)*p[vec[id].se];
            }
        }
        ans += pre;
    }
    cout << ans << "\n";
}