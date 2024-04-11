/*
PROG: cf827a
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
#define MAXN 2000010

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int N;
string s[MAXN];
vector<int> v[MAXN];
int beg[MAXN];
string ans;
int siz;
int id = -1, pos = -1;

int32_t main()
{
	cout << fixed << setprecision(10);	
	ios_base::sync_with_stdio(false);
	if (fopen("cf827a.in", "r"))
	{	
		freopen ("cf827a.in", "r", stdin);
		freopen ("cf827a.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < MAXN; i++)
	{
		beg[i] = -1;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> s[i];
		int x;
		cin >> x;
		for (int j = 0; j < x; j++)
		{
			int a;
			cin >> a;
			a--;
			v[i].PB(a);
			if (beg[a] == -1 || s[i].length() > s[beg[a]].length())
			{
				beg[a] = i;
			}
//			cerr << a << endl;
			siz = max(siz, a + (int) s[i].length());
		}
	}
	ans.resize(siz);
	for (int i = 0; i < siz; i++)
	{
		if (beg[i] == -1)
		{
			if (id == -1)
			{
				ans[i] = 'a';
				continue;
			}
			else
			{
				ans[i] = s[id][pos];
				pos++;
				if (pos == s[id].length())
				{
					pos = -1;
					id = -1;
				}
			}
		}
		else
		{
			if (id == -1 || s[id].length() - pos <= s[beg[i]].length())
			{
				pos = 0;
				id = beg[i];
				ans[i] = s[id][pos];
				pos++;
				if (pos == s[id].length())
				{
					pos = -1;
					id = -1;
				}
			}
			else
			{
				ans[i] = s[id][pos];
				pos++;
				if (pos == s[id].length())
				{
					pos = -1;
					id = -1;
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}