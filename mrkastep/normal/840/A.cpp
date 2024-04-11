#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <complex>
#include <map>

using namespace std;

typedef long long ll;

int a[200200], b[200200], c[200200];

void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; ++i)
        scanf("%d", &b[i]);
    map<int, vector<int> > m;
    sort(a, a + n);
    reverse(a, a + n);
    for(int i = 0; i < n; ++i) {
        m[b[i]].push_back(i);
    }
    for(int i = 0; i < n; ++i) {
        int j = m.begin()->second.back();
        m.begin()->second.pop_back();
        if(m.begin()->second.empty())
            m.erase(m.begin());
        c[j] = a[i];
    }
    for(int i = 0; i < n; ++i)
        printf("%d ", c[i]);
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}