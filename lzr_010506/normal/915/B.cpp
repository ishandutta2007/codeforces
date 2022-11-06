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
int n, pos, l, r;

int main() 
{
	n = read();
	pos = read();
	l = read();
	r = read();
  	if (l == 1 && r == n) cout << 0;
  	else if (l == 1) cout << abs(pos - r) + 1;
  	else if (r == n) cout << abs(pos - l) + 1;
    else cout << min(abs(pos - l) + (r - l) + 2, abs(pos - r) + (r - l) + 2);
    return 0;
}