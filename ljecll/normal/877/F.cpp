/*
PROG: cf877f
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
#define MT make_tuple
#define LB lower_bound
#define UB upper_bound

#define SINF 10007
#define MOD 1000000007
#define INF 1000000861
#define LLINF 1000000000000000861ll
#define CO 1000861
#define EPS 0.000000000000001
#define PI 3.141592653589793
#define MAXN 400010
#define MAGIC 400

typedef int64_t ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> ppi;

int N;
ll K;
ll arr[MAXN];
ll pref[MAXN];
int Q;
ll rt[MAXN], lt[MAXN];
map<ll, int> mp;
vector<ppi> query[MAXN];
ll ans[MAXN];
ll cnt[MAXN];
ll res;
int lf, rg;

int batch(int x)
{
	return x/MAGIC;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	srand(time(NULL));
//	cout << fixed << setprecision(10);	
//	cerr << fixed << setprecision(10);
//	if (fopen("cf877f.in", "r"))
//	{	
//		freopen ("cf877f.in", "r", stdin);
//		freopen ("cf877f.out", "w", stdout);
//	}
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		ll x;
		cin >> x;
		arr[i] = 3 - 2 * x;
	}
	for (int i = 1; i <= N; i++)
	{
		ll x;
		cin >> x;
		arr[i] *= x;
	}
	pref[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		pref[i] = pref[i - 1] + arr[i];
//		cerr << pref[i] << endl;
	}
	for (int i = 0; i <= N; i++)
	{
		mp[pref[i]] = 1;
		mp[pref[i] + K] = 1;
		mp[pref[i] - K] = 1;
	}
	int spam = 0;
	for (auto it = mp.begin(); it != mp.end(); it++)
	{
		it -> second = spam;
//		cerr << it -> first << endl;
		spam++;
	}
	for (int i = 0; i < spam; i++)
	{
		rt[i] = spam;
		lt[i] = spam;
	}
	for (int i = 0; i <= N; i++)
	{
		rt[mp[pref[i]]] = mp[pref[i] + K];
		lt[mp[pref[i]]] = mp[pref[i] - K];
		pref[i] = mp[pref[i]];
	}
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int L, R;
		cin >> L >> R;
		L--;
		query[batch(L)].PB(MP(MP(R, L), i));
	}
	for (int i = 0; i <= batch(N - 1); i++)
	{
		sort(query[i].begin(), query[i].end());
	}
	for (int i = 0; i <= batch(N - 1); i++)
	{
		//solve all the queries
		for (int j = 0; j < spam; j++)
		{
			cnt[j] = 0;
		}
		lf = 0;
		rg = -1;
		res = 0;
		for (int j = 0; j < query[i].size(); j++)
		{
			int L = query[i][j].first.second, R = query[i][j].first.first, id = query[i][j].second;
			while(lf > L)
			{
				lf--;
				res += cnt[rt[pref[lf]]];
				cnt[pref[lf]]++;
			}
			while(rg < R)
			{
				rg++;
				res += cnt[lt[pref[rg]]];
				cnt[pref[rg]]++;
			}
			while(lf < L)
			{
				cnt[pref[lf]]--;
				res -= cnt[rt[pref[lf]]];
				lf++;
			}
			while(rg > R)
			{
				cnt[pref[rg]]--;
				res -= cnt[lt[pref[rg]]];
				rg--;
			}
			ans[id] = res;
		}
	}
	for (int i = 0; i < Q; i++)
	{
		cout << ans[i] << '\n';
	}
	return 0;
	//first sort by batch, then by left endpoint
}