//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii; 

const int maxN = 500 + 10;
const ll mod = 998244353;

map<ll,int> cnt;
map<ll,int> eq;

ll a[maxN];
bool ok[maxN];

ll gcd(ll a, ll b) { 
    return b == 0? a : gcd( b , a % b );
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) { 
        cin >> a[i]; 
        
        {
            ll v = pow(a[i], 1./4);
            while( v * v * v * v < a[i] ) 
                v++;
            while( v * v * v * v > a[i] )
                v--;
            if( v * v * v * v == a[i] ) { 
                cnt[v] += 4;
                ok[i] = true;
                continue;
            }
        }

        {
            ll v = pow(a[i], 1./2);
            while( v * v < a[i] ) 
                v++;
            while( v * v > a[i] )
                v--;
            if( v * v == a[i] ) { 
                cnt[v] += 2;
                ok[i] = true;
                continue;
            }
        }

        {
            ll v = pow(a[i], 1./3);
            while( v * v * v < a[i] ) 
                v++;
            while( v * v * v > a[i] )
                v--;
            if( v * v * v == a[i] ) { 
                cnt[v] += 3;
                ok[i] = true;
            }
        }
    }

    vector<ll> pr;
    for(auto it : cnt) { 
        ll p = it.first;
        pr.push_back(p);
    }

    for(int t = 0; t < 5; t++) { 
        while( pr.size() ) {
            vector<ll> tmp;
            for(auto p: pr) {
                for( int i = 0; i < n; i++ ) 
                    if( !ok[i] && gcd(p, a[i]) > 1 ) {
                        ll v = gcd(p, a[i]);
                        cnt[v]++;
                        cnt[a[i]/v]++;
                        tmp.push_back(a[i]/v);
                        ok[i] = true;
                    }
            }
            pr.clear();
            pr.swap(tmp);
        }

        for(int i = 0; i < n; i++ ) 
            for(int j = 0; j < n; j++)
                if( !ok[i] && !ok[j] && a[i] != a[j] && gcd(a[i],a[j]) > 1 ) {
                    ll v = gcd(a[i],a[j]);
                    cnt[v] += 2;
                    cnt[a[i]/v]++;
                    cnt[a[j]/v]++;
                    ok[i] = true;
                    ok[j] = true;

                    pr.push_back(v);
                    pr.push_back(a[i]/v);
                    pr.push_back(a[j]/v);
                }
    }

    ll z = 1;
    for(int i = 0; i < n; i++)
        if( !ok[i] ) 
            eq[a[i]]++;

    for( auto it : eq ) 
        z = z * (it.second+1) % mod * (it.second + 1) % mod;

    for( auto it : cnt ) 
        z = z * (it.second+1) % mod;

    cout << z << endl;

    return 0;
}