#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}

int main() {
    int n;
    cin>>n;
    map<ll, ll> m;
    for (ll i = 0; i<n*n; ++i) {
        ll a;
        cin>>a;
        m[a]++;
    }
    map<ll, ll>::reverse_iterator rit;
    vector< ll > v;
    for(rit = m.rbegin(); rit != m.rend(); ++rit) {
        while(rit->second > 0) {
            v.push_back(rit->first);
            m[rit->first]--;
            for (ll i = (int)v.size()-2; i>=0; --i) {
                ll g = gcd(v.back(), v[i]);
                m[g] -= 2;
            }
        }
    }

    for (ull i = 0; i<v.size()-1; ++i) {
            cout<<v[i]<<" ";
    }
    cout<<v.back()<<"\n";
	return 0;
}