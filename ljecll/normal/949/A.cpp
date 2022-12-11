/*
PROG: cf949a
LANG: C++11
    _____
  .'     '.
 /  0   0  \
|     ^     |
|  \     /  |
 \  '---'  /
  '._____.'
 */
#include <bits/stdc++.h>

using namespace std;

template<class T>
void readi(T &x)
{
	T input = 0;
	bool negative = false;
	char c = ' ';
	while (c < '-')
	{
		c = getchar();
	}
	if (c == '-')
	{
		negative = true;
		c = getchar();
	}
	while (c >= '0')
	{
		input = input * 10 + (c - '0');
		c = getchar();
	}
	if (negative)
	{
		input = -input;
	}
	x = input;
}
template<class T>
void printi(T output)
{
	if (output == 0)
	{
		putchar('0');
		return;
	}
	if (output < 0)
	{
		putchar('-');
		output = -output;
	}
	int aout[20];
	int ilen = 0;
	while(output)
	{
		aout[ilen] = ((output % 10));
		output /= 10;
		ilen++;
	}
	for (int i = ilen - 1; i >= 0; i--)
	{
		putchar(aout[i] + '0');
	}
	return;
}
template<class T>
void ckmin(T &a, T b)
{
	a = min(a, b);
}
template<class T>
void ckmax(T &a, T b)
{
	a = max(a, b);
}
long long randomize(long long mod)
{
	return ((1ll << 30) * rand() + (1ll << 15) * rand() + rand()) % mod;
}

#define MP make_pair
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second

const long double PI = 4.0 * atan(1.0);
const long double EPS = 1e-20;

#define MAGIC 347
#define SINF 10007
#define CO 1000007
#define INF 1000000007
#define BIG 1000000931
#define LARGE 1696969696967ll
#define GIANT 2564008813937411ll
#define LLINF 2696969696969696969ll

template<class T>
T normalize(T x, T mod = INF)
{
	return (((x % mod) + mod) % mod);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
string s;
multiset<int> ones, zeroes;
vector<vector<int> > ans;

int32_t main()
{
	ios_base::sync_with_stdio(0); 
	srand(time(0));
	//	cout << fixed << setprecision(12);	
	//	cerr << fixed << setprecision(12);
	if (fopen("cf949a.in", "r"))
	{	
		freopen ("cf949a.in", "r", stdin);
		freopen ("cf949a.out", "w", stdout);
	}
	cin >> s;
	N = s.length();
	for (int i = 0; i < N; i++)
	{
		if (s[i] == '1')
		{
			ones.insert(i);
		}
		else
		{
			zeroes.insert(i);
		}
	}
	while(!ones.empty() || !zeroes.empty())
	{
		vector<int> temp;
		if (zeroes.empty())
		{
			cout << "-1\n";
			return 0;
		}
		if (!ones.empty() && *ones.begin() < *zeroes.begin())
		{
			cout << "-1\n";
			return 0;
		}
		ll val = *zeroes.begin();
		temp.PB(val);
		zeroes.erase(zeroes.find(val));
		while(!ones.empty() && val < *ones.rbegin())
		{
			ll ov = *(ones.LB(val));
			if (zeroes.empty() || ov > *zeroes.rbegin())
			{
				break;
			}
			val = *(zeroes.LB(ov));
			ones.erase(ones.find(ov));
			zeroes.erase(zeroes.find(val));
			temp.PB(ov);
			temp.PB(val);
		}
		ans.PB(temp);
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].size();
		for (int j = 0; j < ans[i].size(); j++)
		{
			cout << ' ' << ans[i][j] + 1;
		}
		cout << '\n';
	}
	//K is ones.size() - zeroes.size();
	//001010100
	//	cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}