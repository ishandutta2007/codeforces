/*
PROG: cf825d
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

ll blank;
string s, t;
ll cnt[26];
ll cntt[26];

bool can(ll x)
{
	ll need = 0;
	for (int i = 0; i < 26; i++)
	{
		need += max(0ll, x * cntt[i] - cnt[i]);
	}
	return (need <= blank);
}

int32_t main()
{
	cout << fixed << setprecision(10);	
	ios_base::sync_with_stdio(false);
	if (fopen("cf825d.in", "r"))
	{	
		freopen ("cf825d.in", "r", stdin);
		freopen ("cf825d.out", "w", stdout);
	}
	cin >> s >> t;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '?')
		{
			continue;
		}
		cnt[s[i] - 'a']++;
	}
	for (int i = 0; i < t.length(); i++)
	{
		cntt[t[i] - 'a']++;
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '?')
		{
			blank++;
		}
	}
//	can(2);
	int lo = 0, hi = 1000001;
	while(hi - lo > 1)
	{
		ll mid = (hi + lo)/2;
		if (can(mid))
		{
			lo = mid;
		}
		else
		{
			hi = mid;
		}
	}
	//ans is lo
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != '?')
		{
			continue;
		}
		for (int j = 0; j < 26; j++)
		{
			if (cnt[j] < cntt[j] * lo)
			{
				cnt[j]++;
				s[i] = (j + 'a');
				break;
			}
		}
		if (s[i] == '?')
		{
			s[i] = 'z';
		}
	}
	cout << s << '\n';
	return 0;
}