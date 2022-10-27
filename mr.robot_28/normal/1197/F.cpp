#include<bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int add(int x, int y)
{
	return (x + y) % MOD;
}

int mul(int x, int y)
{
	return (x * 1ll * y) % MOD;
}

typedef vector<int> vec;
typedef vector<vec> mat;

vec mul(const mat& a, const vec& b)
{
	int n = a.size();
	int m = b.size();
	vector<int> c(m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			c[i] = add(c[i], mul(b[j], a[i][j]));
	return c;
}

mat add(const mat& a, const mat& b)
{
	int n = a.size();
	int m = a[0].size();
	mat c(n, vec(m, 0));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			c[i][j] = add(a[i][j], b[i][j]);
	return c;
}

mat mul(const mat& a, const mat& b)
{
	int x = a.size();
	int y = b.size();
	int z = b[0].size();
	mat c(x, vec(z, 0));
	for(int i = 0; i < x; i++)
		for(int j = 0; j < y; j++)
			for(int k = 0; k < z; k++)
				c[i][k] = add(c[i][k], mul(a[i][j], b[j][k]));
	return c;
}

mat binpow(mat a, int d)
{
	int n = a.size();
	mat c = mat(n, vec(n, 0));
	for(int i = 0; i < n; i++) c[i][i] = 1;
	while(d > 0)
	{
		if(d % 2 == 1) c = mul(c, a);
		a = mul(a, a);
		d /= 2;
	}
	return c;
}

int f[3][3];

int extend(int color, vector<int> last_numbers)
{
	vector<int> used(4, 0);
	for(int i = 0; i < 3; i++)
		if(f[color][i])
			used[last_numbers[i]] = 1;
	for(int i = 0; i <= 3; i++)
		if(used[i] == 0)
			return i;
	return 3;
}

vector<int> extend_state(int color, vector<int> last_numbers)
{
	int z = extend(color, last_numbers);
	last_numbers.insert(last_numbers.begin(), z);
	last_numbers.pop_back();
	return last_numbers;
}

vector<int> int2state(int x)
{
	vector<int> res;
	for(int i = 0; i < 3; i++)
	{
		res.push_back(x % 4);
		x /= 4;
	}
	return res;
}

int state2int(const vector<int>& x)
{
	int res = 0;
	int deg = 1;
	for(auto y : x)
	{
		res += deg * y;
		deg *= 4;
	}
	return res;
}

mat form_matrix(int color)
{
	mat res(64, vec(64, 0));
	for(int i = 0; i < 64; i++)
	{
		int j = state2int(extend_state(color, int2state(i)));
		res[j][i] = add(res[j][i], 1);
	}
	return res;
}

mat color_matrices[3];
mat full_matrix;

vector<pair<int, int> > colored[1043];
int len[1043];
int dp[1043][4];

mat full_pows[31];

void precalc_pows()
{
	full_pows[0] = full_matrix;
	for(int i = 0; i <= 30; i++)
		full_pows[i + 1] = mul(full_pows[i], full_pows[i]);
}

vec powmul(int d, vec b)
{
	for(int i = 0; i <= 30; i++)
	{
		if(d % 2 == 1) 
			b = mul(full_pows[i], b);
		d /= 2;
	}
	return b;
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> len[i];
	int m;
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		int x, y, c;
		cin >> x >> y >> c;
		--x;
		--y;
		--c;
		colored[x].push_back(make_pair(y, c));
	}
	for(int i = 0; i < n; i++)
		sort(colored[i].begin(), colored[i].end());
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			cin >> f[i][j];
	
	for(int i = 0; i < 3; i++)
		color_matrices[i] = form_matrix(i);
	full_matrix = color_matrices[0];
	for(int i = 1; i < 3; i++)
		full_matrix = add(full_matrix, color_matrices[i]);
	precalc_pows();
		
	dp[0][0] = 1;
	for(int i = 0; i < n; i++)
	{
		vec cur(64);
		cur[state2int({3, 3, 3})] = 1;
		int last = 0;
		for(auto x : colored[i])
		{
			cur = powmul(x.first - last, cur);
			cur = mul(color_matrices[x.second], cur);
			last = x.first + 1;
		}
		cur = powmul(len[i] - last, cur);
		for(int j = 0; j < 4; j++)
			for(int k = 0; k < 64; k++)
			{
				vector<int> s = int2state(k);
				dp[i + 1][j ^ s[0]] = add(dp[i + 1][j ^ s[0]], mul(dp[i][j], cur[k]));
			}
	}
	cout << dp[n][0] << endl;
}