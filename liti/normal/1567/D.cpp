//be naame khodaa
#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <numeric>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back

const int N = 12;

int pww[N];

vector<int> ans; 

inline vector<int> gg(int num) { 
    vector<int> res; 
    for(; num; num /= 10)
        res.pb(num % 10);
    return res; 
}

int bt(int s, int rem) {
    int orem = rem; 

    if (s == 1 || rem == 1) { 
        rem--; 
        ans.pb(s);
        return 1;
    }

    auto&& v = gg(s); 
    int sz = v.size(); 

    if (s % pww[sz-1] != 0) 
        rem -= bt(s % pww[sz-1], max(1, rem - v.back()) ); 

    if (rem == 1) { 
        ans.pb(pww[sz-1]*v.back());
        rem --; 
        return orem - rem;
    }

    if (v.back() == 1) { 
        rem -= bt(9*pww[sz-2], rem-1); 
        rem -= bt(pww[sz-2], rem); 

        return orem - rem; 
    }


    rem -= bt(pww[sz-1], max(1, rem - v.back() + 1));
    v.back()--; 

    rem -= bt(pww[sz-1] * v.back(), rem);

    return orem - rem;
}

void solve() {
    int s, n; 
    cin >> s >> n;

    ans.clear();
    bt(s, n); 

    for(auto x: ans)
        cout << x << ' ';
    cout << '\n';
}

int main() {
    pww[0] = 1; 
    for(int i = 1; i < N; i++) 
        pww[i] = pww[i-1] * 10; 

    ios::sync_with_stdio(false); cin.tie(0); 
    int t;
    cin >> t;
    while(t--) 
        solve();
    return 0;
}