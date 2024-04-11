/*
PROG: cf860c
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
long long getrand()
{
	long long rand1 = (rand() % 536870912);
	long long rand2 = (rand() % 536870912);
	return (rand1 * 536870912ll + rand2);
}

#define MP make_pair
#define PB push_back

#define MAGIC 400
#define SINF 10001
#define INF 1000000861
#define LLINF 1000000000000000861ll
#define MOD 1000000007
#define CO 1000861
#define EPS 0.000000000000001
#define PI 3.141592653589793
#define MAXN 1000010

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<ll> point;

int N, E;
vector<string> pretest, systest;
vector<int> badp, bads;
vector<pair<string, int> > ans;
int nump[MAXN], nums[MAXN];
bool used[MAXN];
vector<int> vp, vs, num;

int32_t main()
{
	srand(time(NULL));
	cout << fixed << setprecision(10);	
	cerr << fixed << setprecision(10);
	ios_base::sync_with_stdio(false);
	if (fopen("cf860c.in", "r"))
	{	
		freopen ("cf860c.in", "r", stdin);
		//freopen ("cf860c.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		bool idx;
		cin >> idx;
		if (idx)
		{
			pretest.PB(s);
		}
		else
		{
			systest.PB(s);
		}
	}
	E = pretest.size();
	for (int i = 0; i < pretest.size(); i++)
	{
		bool isnum = true;
		for (int j = 0; j < pretest[i].length(); j++)
		{
			if (!isdigit(pretest[i][j]))
			{
				isnum = false;
			}
		}
		if (pretest[i][0] == '0')
		{
			isnum = false;
		}
		if (isnum)
		{
			nump[i] = stoi(pretest[i]);
			used[nump[i]] = true;
			if (E + 1 <= nump[i] && nump[i] <= N)
			{
				badp.PB(i);
			}
		}
	}
	for (int i = 0; i < systest.size(); i++)
	{
		bool isnum = true;
		for (int j = 0; j < systest[i].length(); j++)
		{
			if (!isdigit(systest[i][j]))
			{
				isnum = false;
			}
		}
		if (systest[i][0] == '0')
		{
			isnum = false;
		}
		if (isnum)
		{
			nums[i] = stoi(systest[i]);
			used[nums[i]] = true;
			if (1 <= nums[i] && nums[i] <= E)
			{
				bads.PB(i);
			}
		}
	}
	for (int i = 100000; i < 1000000; i++)
	{
		if (!used[i])
		{
			num.PB(i);
		}
	}
	for (int i = 1; i <= E; i++)
	{
		if (!used[i])
		{
			vp.PB(i);
		}
	}
	for (int i = E + 1; i <= N; i++)
	{
		if (!used[i])
		{
			vs.PB(i);
		}
	}
	while(!badp.empty() || !bads.empty())
	{
		if (!badp.empty() && !vp.empty())
		{
			int idx = badp.back();
			badp.pop_back();
			vs.PB(nump[idx]);
			ans.PB(MP(pretest[idx], vp.back()));
			pretest[idx] = to_string(vp.back());
			nump[idx] = vp.back();
			vp.pop_back();
		}
		else if (!bads.empty() && !vs.empty())
		{
			int idx = bads.back();
			bads.pop_back();
			vp.PB(nums[idx]);
			ans.PB(MP(systest[idx], vs.back()));
			systest[idx] = to_string(vs.back());
			nums[idx] = vs.back();
			vs.pop_back();
		}
		else if (!badp.empty())
		{
			int idx = badp.back();
			badp.pop_back();
			vs.PB(nump[idx]);
			ans.PB(MP(pretest[idx], num.back()));
			pretest[idx] = to_string(num.back());
			nump[idx] = num.back();
			num.pop_back();
		}
		else if (!bads.empty())
		{
			int idx = bads.back();
			bads.pop_back();
			vp.PB(nums[idx]);
			ans.PB(MP(systest[idx], num.back()));
			systest[idx] = to_string(num.back());
			nums[idx] = num.back();
			num.pop_back();
		}
	}
	for (int i = 0; i < pretest.size(); i++)
	{
		if (1 <= nump[i] && nump[i] <= E)
		{
			continue;
		}
		ans.PB(MP(pretest[i], vp.back()));
		pretest[i] = vp.back();
		vp.pop_back();
	}
	for (int i = 0; i < systest.size(); i++)
	{
		if (E + 1 <= nums[i] && nums[i] <= N)
		{
			continue;
		}
		ans.PB(MP(systest[i], vs.back()));
		systest[i] = vs.back();
		vs.pop_back();
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
	{
		cout << "move " << ans[i].first << ' ' << ans[i].second << '\n';
	}
	return 0;
}