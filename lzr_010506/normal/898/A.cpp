#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define ll long long
#define X first
#define Y second
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define mod 1000000007
using namespace std;

int main()
{
	long long x;
	cin >> x;
	if(x % 10 >= 5) x = x / 10 * 10 + 10;
	else x = x / 10 * 10;
	cout << x;
	return 0;
}