//be naame khodaa
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

inline int in(){ int x, y; y = scanf("%d", &x); return x; }

const int N = 1000*1000 + 10;

int n; 
vector<ll> calc() { 
    vector<ll> ret;
    ll last = 0;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        if(i)
            ret.push_back( x-last ); 
        last = x;
    }
    sort(ret.begin(), ret.end());
    ret.push_back(last);
    return ret;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); 

    cin >> n;
    auto a = calc();
    auto b = calc();
    cout << (a==b?"Yes":"No") << endl;

    return 0;
}