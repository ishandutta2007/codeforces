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
#include <complex>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

bool solve() {
    
    int n;
    
    cin >> n;

    vec< int > a(n), ans(1e3 + 10, 0);

    for(int i = 1;i <= n;i++) a[i - 1] = i;

    while(1) {
        sort(ALL(a));
        reverse(ALL(a));
        int value = -1;
        for(int i = 0;i < n && value == -1;i++) {
            for(int j = 2;j * j <= a[i];j++) {
                if(a[i] % j) continue;
                value = j;
                break;
            }
            if(value == -1 && a[i] > 1) value = a[i];
        }
        if(value == -1) break;
        ans[value]++;
        for(int i = 0;i < n;i++) {
            if(a[i] % value == 0) a[i] /= value;
        }
    }

    vec< int > mas;

    for(int i = 2;i <= 1e3;i++) {
        int value = 1;
        for(int j = 0;j < ans[i];j++) {
            value *= i;
            mas.push_back(value);
        }
    }

    cout << (int)mas.size() << '\n';
    for(int i = 0;i < (int)mas.size();i++) cout << mas[i] << ' ';
    cout << '\n';

    return true;
}

int main() {
    
    //while(solve());
    solve();  

    return 0;
}