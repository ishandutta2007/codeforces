/*
PROG: cf827b
LANG: C++
    _____
  .'     '.
 /  0   0  \
|     ^     |
|  \     /  |
 \  '---'  /
  '._____.'
*/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

long long readi()
{
	long long input = 0;
	char c = ' ';
	while (c < '-')
	{
		c = getchar();
	}
	bool negative = false;
	if (c == '-')
	{
		negative = true;
		c = getchar();
	}
	while (c >= '0')
	{
		input = 10 * input + (c - '0');
		c = getchar();
	}
	if (negative)
	{
		input = -input;
	}
	return input;
}
string reads()
{
	string input = "";
	char c = ' ';
	while (c <= ' ')
	{
		c = getchar();
	}
	while (c > ' ')
	{
		input += c;
		c = getchar();
	}
	return input;
}
void printi(long long output)
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
	vector<char> vout;
	while(output)
	{
		vout.push_back((output % 10) + '0');
		output /= 10;
	}
	for (int i = vout.size() - 1; i >= 0; i--)
	{
		putchar(vout[i]);
	}
	return;
}
void prints(string output)
{
	for (int i = 0; i < output.length(); i++)
	{
		putchar(output[i]);
	}
	return;
}

#define MP make_pair
#define PB push_back

#define SINF 10001
#define INF 1000000861
#define MOD 1000000007
#define LLINF 1000000000000000861ll
#define CO 1000861
#define EPS 0.000000000000001
#define PI 3.141592653589793

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int N, L, K;
int ans;
int ite;

bool can(ll x)
{
	//x - 1 nonleaves, 2 leaves
	//you can only have x - 2 for each leaf
	ll leaf, nonleaf;
	leaf = L;
	nonleaf = K;
	leaf -= 2;
	nonleaf -= (x - 1);
	if (leaf * ((x/2) - 1) < nonleaf)
	{
		return false;
	}
	return true;
}

int32_t main()
{
	cout << fixed << setprecision(10);	
	ios_base::sync_with_stdio(false);
	if (fopen("cf827b.in", "r"))
	{	
		freopen ("cf827b.in", "r", stdin);
		freopen ("cf827b.out", "w", stdout);
	}
	cin >> N >> L;
	K = N - L;
	//minimum diameter of tree with N nodes and K leaves
	for (int i = 2; i < N; i++)
	{
		if (can(i))
		{
			ans = i;
			break;
		}
	}
	cout << ans << '\n';
	for (int i = 0; i < ans; i++)
	{
		cout << i + 1 << ' ' << i + 2 << '\n';
	}
	int mid = (ans/2);
	ite = ans + 1;
	L -= 2;
	K -= (ans - 1);
	while(K)
	{
		L--;
		cout << mid + 1 << ' ' << ite + 1 << '\n';
		for (int i = 1; i <= min(K, (ans/2) - 1); i++)
		{
			cout << ite + 1 << ' ' << ite + 2 << '\n';
			ite++;
		}
		ite++;
		K -= min(K, (ans/2) - 1);
	}
	for (int i = 0; i < L; i++)
	{
		cout << mid + 1 << ' ' << ite + 1 << '\n';
		ite++;
	}
	return 0;
}