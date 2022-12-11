/*
PROG: cf832b
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

int Q;
bool good[26];
string s, t, rs;
int pos = -1;
int revpos = -1;

int32_t main()
{
	cout << fixed << setprecision(10);	
	ios_base::sync_with_stdio(false);
	if (fopen("cf832b.in", "r"))
	{	
		freopen ("cf832b.in", "r", stdin);
		freopen ("cf832b.out", "w", stdout);
	}
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		good[s[i] - 'a'] = true;
	}
	cin >> s >> Q;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '*')
		{
			pos = i;
		}
	}
	rs = s;
	reverse(rs.begin(), rs.end());
	for (int i = 0; i < rs.length(); i++)
	{
		if (rs[i] == '*')
		{
			revpos = i;
		}
	}
//	cerr << revpos << endl;
	while(Q--)
	{
		cin >> t;
		bool flag = true;
		if (pos != -1)
		{
			if (t.length() + 1 < s.length())
			{
				cout << "NO\n";
				continue;
			}
			for (int i = 0; i < pos; i++)
			{
				if (s[i] == '?')
				{
					if (!good[t[i] - 'a'])
					{
						flag = false;
					}
				}
				else
				{
					if (s[i] != t[i])
					{
						flag = false;
					}
				}
			}
			reverse(t.begin(), t.end());
			for (int i = 0; i < pos; i++)
			{
				t.pop_back();
			}
			for (int i = 0; i < revpos; i++)
			{
				if (rs[i] == '?')
				{
					if (!good[t[i] - 'a'])
					{
						flag = false;
					}
				}
				else
				{
					if (rs[i] != t[i])
					{
						flag = false;
					}
				}
			}
			reverse(t.begin(), t.end());
			for (int i = 0; i < revpos; i++)
			{
				t.pop_back();
			}
			for (int i = 0; i < t.length(); i++)
			{
				if (good[t[i] - 'a'])
				{
					flag = false;
				}
			}
		}
		else
		{
			if (t.length() != s.length())
			{
				cout << "NO\n";
				continue;
			}
			for (int i = 0; i < s.length(); i++)
			{
				if (s[i] == '?')
				{
					if (!good[t[i] - 'a'])
					{
						flag = false;
					}
				}
				else
				{
					if (s[i] != t[i])
					{
						flag = false;
					}
				}
			}
		}
		if (flag)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}