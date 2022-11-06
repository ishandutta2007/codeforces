#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
//#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define mod 1000000007
#define sz(x) (int)(x).size()
#define vi vector<int>
using namespace std;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

int n, k;
int a[111];
int main()
{
    n=read(), k = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    int ans = 0x3f3f3f3f;
    rep(i, 1, n) if(k % a[i] == 0) ans = min(ans, k/a[i]);
    cout << ans << endl;
    return 0;
}