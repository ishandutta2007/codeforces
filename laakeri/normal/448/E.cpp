#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

set<ll> ds;

ll co=0;

void dfs (ll x, ll de){
    if (co==100000) return;
    if (x==1||de==0){
        cout<<x<<" ";
        co++;
    }
    else{
        for (ll d:ds){
            if (d>x) break;
            if (x%d==0){
                dfs(d,de-1);
            }
        }
    }
}

int main(){
    ll x,k;
    cin>>x>>k;
    vector<ll> ps;
    for (ll i=2;;i++){
        if (i*i>x){
            break;
        }
        int f=0;
        for (ll p:ps){
            if (i%p==0){
                f=1;
                break;
            }
            if (p*p>i) break;
        }
        if (!f){
            ps.push_back(i);
        }
    }
    ll xx=x;
    for (ll p:ps){
        while (xx%p==0){
            vector<ll> in;
            for (ll a:ds){
                in.push_back(a*p);
            }
            in.push_back(p);
            for (ll d:in){
                ds.insert(d);
            }
            in.clear();
            xx/=p;
        }
    }
    if (xx>1){
        vector<ll> in;
        for (ll a:ds){
            in.push_back(a*xx);
        }
        in.push_back(xx);
        for (ll d:in){
            ds.insert(d);
        }
        in.clear();
    }
    ds.insert(1);
    dfs(x,k);
}