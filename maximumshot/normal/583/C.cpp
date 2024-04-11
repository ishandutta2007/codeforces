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

int gcd(int x, int y) {
    return (x == 0?y : gcd(y % x, x));
}

bool solve() {

    int n;

    cin >> n;

    vec< int > a(n * n);
    map< int , int > m;
    for(int i = 0;i < n * n;i++) cin >> a[i], m[a[i]]++;
    vec< int > b;

    sort(a.rbegin(), a.rend());

    while(!m.empty()) {
        
        int v = (--m.end())->first;

        m[v]--;

        if(m[v] == 0) m.erase(v);

        for(int j = 0;j < (int)b.size();j++) {
            int value = b[j];
            m[gcd(value, v)] -= 2;
            if(m[gcd(value, v)] == 0) {
                m.erase(gcd(value, v));
            }
        }

        b.push_back(v);
    }

    for(int i = 0;i < n;i++) cout << b[i] << " "; 
    cout << '\n';

    return true;
}   

int main() {

    //while(solve());
    solve();

    return 0;
}