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

int main() {
    ios_base::sync_with_stdio(0);
    int n, a, b;
    cin >> n >> a >> b;
    int h[n];
    for(int i = 0; i < n; ++i)
            cin >> h[i];
    sort(h, h + n);
    reverse(h, h + n);
    int r = h[a - 1], l = h[a];
    if(l == r)
         cout << 0;
    else
        cout << r - l;
    cin >> n;
    return 0;
}