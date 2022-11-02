#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
using namespace std;

typedef long long ll;
#define F first
#define S second
#define pb push_back

bool cmp(pair<int, int> a, pair<int, int> b) {
     return a.F > b.F || a.F == b.F && a.S < b.S;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i)
            cin >> a[i].F >> a[i].S;
    sort(a, a + n, cmp);
    int cnt = 0;
    for(int i = 0; i < n; ++i)
            if(a[i] == a[k - 1])
                    ++cnt;
    cout << cnt << endl;
    cin >> n; 
    return 0;
}