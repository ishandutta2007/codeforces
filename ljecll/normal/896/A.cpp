/*
PROG: cf896a
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
int sgn(long long x)
{
	if (x < 0) 
	{
		return -1;
	}
	if (x > 0) 
	{
		return 1;
	}
	return 0;
}
long long randomize(long long x)
{
	return (((1ll << 31) * rand()) + rand()) % x;
}

#define MP make_pair
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second

const long double PI = 4.0 * atan(1.0);
const long double EPS = 0.00000000000000000001;

#define SINF 10007
#define INF 1000000007
#define LLINF 2696969696969696969ll
#define CO 1000037

long long normalize(long long x)
{
	return (((x % INF) + INF) % INF);
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int Q;
ll len[1000010];
string s = "What are you doing at the end of the world? Are you busy? Will you save us?";
string t = "What are you doing while sending \"";
string u = "\"? Are you busy? Will you send \"";
string v = "\"?";

char query(ll idx, ll rank)
{
	if (rank < 0)
	{
		return '.';
	}
	if (idx == 0)
	{
		if (rank >= s.length())
		{
			return '.';
		}
		return s[rank];
	}
	if ((ll) 0 <= rank && rank < t.length())
	{
		return t[rank];
	}
	if (idx >= 54 || ((ll) t.length() <= rank && rank < (ll) t.length() + len[idx - 1]))
	{
		return query(idx - 1, rank - t.length());
	}
	if ((ll) t.length() + len[idx - 1] <= rank && rank < (ll) t.length() + len[idx - 1] + u.length())
	{
		return u[rank - t.length() - len[idx - 1]];
	}
	if ((ll) t.length() + len[idx - 1] + u.length() <= rank && rank < (ll) t.length() + len[idx - 1] + u.length() + len[idx - 1])
	{
		return query(idx - 1, rank - t.length() - len[idx - 1] - u.length());
	}
	if ((ll) t.length() + len[idx - 1] + u.length() + len[idx - 1] <= rank && rank < (ll) t.length() + len[idx - 1] + u.length() + len[idx - 1] + v.length())
	{
		return v[rank - t.length() - len[idx - 1] - u.length() - len[idx - 1]];
	}
	return '.';
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	srand(time(0));
	//	cout << fixed << setprecision(12);	
	//	cerr << fixed << setprecision(12);
	if (fopen("cf896a.in", "r"))
	{	
		freopen ("cf896a.in", "r", stdin);
		freopen ("cf896a.out", "w", stdout);
	}
	cin >> Q;
	len[0] = s.length();
	string z = t + s + u + s + v;
	string m;
//	getline(cin, m);
//	assert(m == z);
//	cerr << m << endl << z << endl;
//	cerr << t << s << u << s << v << endl;
	for (int i = 1; i <= 55; i++)
	{
		len[i] = 2 * len[i - 1] + t.length() + u.length() + v.length();
	}
//	cerr << len[54] << endl;
	for (int i = 56; i < 1000000; i++)
	{
		len[i] = LLINF;
	}
	while(Q--)
	{
		ll N, K;
		cin >> N >> K;
		K--;
		cout << query(N, K);
	}
	cout << '\n';
	return 0;
}