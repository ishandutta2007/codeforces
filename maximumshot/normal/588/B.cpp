#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = 3.1415926535897932384626433832795;

ll n;
vec< vec< ll > > a;
vec< char > prime;
vec< ll > f;

bool check(ll x) {
    
    if(x <= 1e6) {
        for(int i = 0;i < (int)a[x].size();i++) {
            int j = i;
            while(j < (int)a[x].size() && a[x][i] == a[x][j]) j++; j--;
            if((j - i + 1) > 1) return 0;
            i = j;
        }
    }else {
        vec< int > tmp;
        int i = 0, j = 0;
        ll value = n / x;
        while(i < (int)f.size() && j < a[value].size()) {
            if(f[i] < a[value][j]) tmp.push_back(f[i++]);
            else if(f[i] > a[value][j]) tmp.push_back(a[value][j++]);
            else i++, j++;
        }
        while(i < (int)f.size()) tmp.push_back(f[i++]);
        while(j < (int)a[value].size()) tmp.push_back(a[value][j++]);
        for(int i = 0;i < (int)tmp.size();i++) {
            int j = i;
            while(j < (int)tmp.size() && tmp[i] == tmp[j]) j++; j--;
            if((j - i + 1) > 1) return 0;
            i = j;
        }
    }


    return 1;
}

bool solve() {
    
    cin >> n;

    if(n == 1) {
        cout << 1 << '\n';
        return true;
    }

    ll value = n;
    for(ll x = 2;x * x <= value;x++) {
        if(value % x == 0) {
            f.push_back(x);
            value /= x;
            x--;
        }
    }

    if(value > 1) f.push_back(value);

    a.resize(1e6 + 10);
    prime.resize(1e6 + 10, 1);

    prime[0] = prime[1] = 0;

    for(ll i = 2;i * i <= 1e6;i++) {
        if(!prime[i]) continue;
        for(ll j = i * i;j <= 1e6;j += i) {
            prime[j] = 0;
        }
    }

    for(ll i = 2;i <= 1e6;i++) {
        if(!prime[i]) continue;
        for(ll j = i;j <= 1e6;j += i) {
            ll value = j;
            while(value % i == 0) {
                a[j].push_back(i);
                value /= i;
            }
        }
    }

    ll ans = 1;

    for(ll x = 1;x * x <= n;x++) {
        if(n % x) continue;
        if(check(x)) ans = max(ans, x);
        if(x != n / x && check(n / x)) ans = max(ans, n / x); 
    }

    cout << ans << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}