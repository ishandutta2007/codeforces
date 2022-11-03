#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ld long double
typedef pair<ld , ld> shit;
const int maxn = 1e3 + 20;
const ld epsilon = 1e-7;

ld ans[maxn];

ll r , x[maxn];

ld get(int a , int b)
{
	ld L = ans[b] , R = 1e9;
	for(int i = 0; i < 100; i++)
	{
		ld m = (L + R) / 2;
		if((x[a] - x[b]) * (x[a] - x[b]) + (ans[b] - m) * (ans[b] - m) >= 4 * r * r)
			R = m;
		else
			L = m;
	}
	return R;
}

int main()
{
	int n;
	cin >> n >> r;
	
	for(int i = 0; i < n; i++)
		cin >> x[i];

	for(int i = 0; i < n; i++)
	{
		ld mx = r;
		for(int j = 0; j < i; j++)
			if(abs(x[i] - x[j]) <= 2 * r)
				mx = max(mx , get(i , j));
		ans[i] = mx;
	}

	cout << fixed << setprecision(20);

	for(int i = 0; i < n; i++)
		cout << ans[i] << " ";
	cout << endl;
}