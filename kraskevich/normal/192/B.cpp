#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <list>
#include <stdlib.h>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;

typedef long long i64;
#define MP make_pair
#define F first
#define S second
#define pii pair<int, int>
#define forn for(int i = 0; i < n; ++i)
int f[100000];

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    int a[n];
    forn cin >> a[i];
    
    f[0] = a[0];
    f[1] = min(a[1], a[0]);
    
    for(int i = 2; i < n; ++i)
    {
            int cur = max(f[i - 1], f[i - 2]);
            f[i] = min(cur, a[i]);
    }
    
    cout << f[n - 1];
    
    cin >> n;
    return 0;
}