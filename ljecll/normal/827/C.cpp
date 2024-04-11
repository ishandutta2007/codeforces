/*
PROG: cf827c
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
#define MAXN 100010

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int N;
int mp[300];
string s;
int arr[MAXN];
int Q;
int tree[4][11][11][MAXN];

//valmod, mod, pos
ll query(int v, int x, int w, int idx)
{
	ll sum = 0ll;
	for (int e = idx + 1; e > 0; e -= (e & (-e)))
	{
		sum += tree[v][x][w][e];
	}
	return sum;
}
void update(int v, int x, int w, int idx, ll val)
{
	for (int e = idx + 1; e <= N; e += (e & (-e)))
	{
		tree[v][x][w][e] += val;
	}
    return;
}
ll range(int v, int x, int w, int lt, int rt)
{
	if (lt == 0)
	{
		return query(v, x, w, rt);
	}
	return query(v, x, w, rt) - query(v, x, w, lt - 1);
}

int32_t main()
{
	cout << fixed << setprecision(10);	
	ios_base::sync_with_stdio(false);
	if (fopen("cf827c.in", "r"))
	{	
		freopen ("cf827c.in", "r", stdin);
		freopen ("cf827c.out", "w", stdout);
	}
	mp['A'] = 0;
	mp['C'] = 1;
	mp['T'] = 2;
	mp['G'] = 3;
	cin >> s >> Q;
	N = s.length();
	for (int i = 0; i < N; i++)
	{
		arr[i] = mp[s[i]];
		for (int j = 1; j <= 10; j++)
		{
			update(arr[i], i % j, j, i, 1);
		}
//		cerr << arr[i] << endl;
	}
	for (int i = 0; i < Q; i++)
	{
		int qid;
		cin >> qid;
		if (qid == 1)
		{
			int pos;
			int a;
			char c;
			cin >> pos >> c;
			a = mp[c];
			pos--;
			for (int j = 1; j <= 10; j++)
			{
				update(arr[pos], pos % j, j, pos, -1);
				update(a, pos % j, j, pos, 1);
			}
			arr[pos] = a;
		}
		else
		{
			int lt, rt;
			string q;
			cin >> lt >> rt >> q;
			lt--;
			rt--;
			int mod = q.length();
			ll res = 0;
			for (int j = 0; j < mod; j++)
			{
				res += range(mp[q[j]], (lt + j) % mod, mod, lt, rt);
			}
			cout << res << '\n';
		}
	}
	return 0;
}