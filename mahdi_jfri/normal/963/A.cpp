#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define int ll

const int maxn = 1e5 + 20;
const int mod = 1e9 + 9;

void ok(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int pw(int a , int b)
{
	if(!b)
		return 1;

	int x = pw(a , b / 2);

	x = 1LL * x * x % mod;
	if(b & 1)
		x = 1LL * x * a % mod;

	return x;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	int n , a , b , k;
	cin >> n >> a >> b >> k >> s;

	int sum = 0;

	for(int i = 0; i < k; i++)
		ok(sum += 1LL * ((s[i] == '+')? 1 : -1) * 1LL * pw(a , n - i) * pw(b , i) % mod);

	int tmp = 1LL * pw(b , k) * pw(pw(a , mod - 2) , k) % mod;
	ok(tmp -= 1);

	int ans;

	if(tmp != 0)
	{
		ans = pw(tmp + 1 , (n + 1) / k) - 1;
		ok(ans);
		ans = 1LL * ans * pw(tmp , mod - 2) % mod;
	}

	if(tmp == 0)
		ans = ((n + 1) / k) % mod;

	ans = 1LL * ans * sum % mod;

	cout << ans << endl;
}