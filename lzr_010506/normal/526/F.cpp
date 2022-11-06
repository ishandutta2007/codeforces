#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n, a[300010], Max[300010], Min[300010], sum[300010];
ll ans;

void Solve(int l, int r)
{
	if(l > r) return;
	int mid = (l + r) >> 1;
	Max[mid + 1] = Min[mid + 1] = a[mid + 1];
	for(int i = mid + 2; i <= r; i ++)
		Max[i] = max(Max[i - 1], a[i]),
		Min[i] = min(Min[i - 1], a[i]);
	Max[mid] = Min[mid] = a[mid];
	for(int i = mid - 1; i >= l; i --)
		Max[i] = max(Max[i + 1], a[i]),
		Min[i] = min(Min[i + 1], a[i]);
	/*
	cout << l << " " << r << endl;
	for(int i = l; i <= r; i ++)
		cout << Min[i] << " ";
	cout << endl;
	for(int i = l; i <= r; i ++)
		cout << Max[i] << " ";
	cout << endl;
	*/

	for(int i = mid + 1; i <= r; i ++)
	{
		int nowx = i - Max[i] + Min[i];
		//cout << nowx << endl;
		if(nowx >= l && nowx <= mid && Max[nowx] <= Max[i] && Min[nowx] >= Min[i]) ans ++;
	}
	//cout << ans << endl;

	for(int i = mid; i >= l; i --)
	{
		int nowx = i + Max[i] - Min[i];
		//cout << nowx << endl;
		if(nowx <= r && nowx >= mid && Max[nowx] <= Max[i] && Min[nowx] >= Min[i]) ans ++;
	}
	//cout << ans << endl;

	int L = mid + 1, R = mid + 1;
	// cout << L << " " << R;
	for(int i = mid; i >= l; i --)
	{
		while(R <= r && Min[R] >= Min[i]) sum[Max[R] - R + mid] ++, R ++;
		while(L < R && Max[L] <= Max[i]) sum[Max[L] - L + mid] --, L ++;
		ans += sum[Min[i] - i + mid];
	}
	//reverse
	for(int i = L; i < R; i ++) sum[Max[i] - i + mid] --;
	L = mid;
	R = mid;
	for(int i = mid + 1; i <= r; i ++)
	{
		while(R >= l && Min[R] >= Min[i]) sum[Max[R] + R - mid] ++, R --;
		while(L > R && Max[L] <= Max[i]) sum[Max[L] + L - mid] --, L --;
		ans += sum[Min[i] + i - mid];
	}
	for(int i = L; i > R; i --) sum[Max[i] + i - mid] --;
	Solve(l, mid - 1);
	Solve(mid + 1, r);
}

int main()
{
	n = read();
	for(int i = 1; i <= n; i ++)
	{
		int x, y;
		x = read();
		y = read();
		a[x] = y;
	}
	Solve(1, n);
	cout << ans;
	return 0;
}