#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <functional>
#include <sstream>
#include <fstream>
#include <valarray>
#include <complex>
#include <queue>
#include <cassert>
#include <bitset>
using namespace std;

#ifdef LOCAL
#define debug_flag false
#else
#define debug_flag false
#endif

#define dbg(args...) { if (debug_flag) { _print(_split(#args, ',').begin(), args); cerr << endl; } else { void(0);} }

vector<string> _split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return v;
}

void _print(vector<string>::iterator) {}
template<typename T, typename... Args>
void _print(vector<string>::iterator it, T a, Args... args) {
	string name = it -> substr((*it)[0] == ' ', it -> length());
	if (isalpha(name[0]))
		cerr << name  << " = " << a << " ";
	else
		cerr << name << " ";
	_print(++it, args...);
}

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42;
#endif

typedef long long int int64;

typedef long long ll;

const int N = (int)1e6 + 10;

int add(int a, int b, int m)
{
	a += b;
	return a < m ? a : a - m;
}

char str[N];
int tmp[5][N];
int cnt[N];
int lcp[N];
int revArr[N];
int *pos = tmp[0];
int *arr = tmp[1], *narr = tmp[2];
int *col = tmp[3], *ncol = tmp[4];

void buildSA(int n)
{
	int classes = 0;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++)
	{
		cnt[(int)str[i]]++;
		classes = max(classes, str[i] + 1);	
	}
	pos[0] = 0;
	for (int i = 1; i < classes; i++)
		pos[i] = pos[i - 1] + cnt[i - 1];
	for (int i = 0; i < n; i++)
	{
		col[i] = str[i];
		arr[pos[col[i]]++] = i;
	}

	pos[0] = 0;
	for (int i = 1; i < classes; i++)
		pos[i] = pos[i - 1] + cnt[i - 1];

	for (int shift = 1; shift < n; shift *= 2)
	{
		for (int i = 0; i < n; i++)
		{
			int npos = arr[i] - shift;
			if (npos < 0)
				npos += n;
			narr[pos[col[npos]]++] = npos;
		}

		pos[0] = 0;
		ncol[narr[0]] = 0;
		for (int i = 1; i < n; i++)
		{
			ncol[narr[i]] = ncol[narr[i - 1]];
			if (col[narr[i]] != col[narr[i - 1]] || col[add(narr[i], shift, n)] != col[add(narr[i - 1], shift, n)])
				pos[++ncol[narr[i]]] = i;
		}

		swap(col, ncol);
		swap(arr, narr);

		if (col[arr[n - 1]] == n - 1)
			break;
	}
}

void calcLcp(int n)
{
	for (int i = 0; i < n; i++)
		revArr[arr[i]] = i;

	int l = 0;
	for (int i = 0; i < n; i++)
	{
		if (revArr[i] == n - 1)
			l = 0;
		else
		{
			int near = arr[revArr[i] + 1];
			while (str[near + l] == str[i + l])
				l++;
			lcp[revArr[i]] = l;
		}
		l = max(0, l - 1);
	}
}

const int LOGN = 19;
int n;
int bal[N];
map<int, vector<int> > bal_list;

int max_len[N];
int pow2[N];
int st[N][LOGN];

int get_min(int l, int r)
{
	assert(l <= r);
	int p = pow2[r - l + 1];
	return min(st[l][p], st[r - (1 << p) + 1][p]);
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	scanf("%d", &n);
	scanf("%s", str);
	str[n++] = 0;
	buildSA(n);
	calcLcp(n);
	n--;

	for (int i = 0; i < n; i++)
	{
		if (i != 0)
			bal[i] = bal[i - 1];
		if (str[i] == '(')
			bal[i]++;
		else
			bal[i]--;
		bal_list[bal[i]].push_back(i);
	}

	for (int i = 1; i < LOGN; i++)
		pow2[1 << i] = 1;
	for (int i = 1; i < N; i++)
		pow2[i] += pow2[i - 1];

	for (int i = 0; i < n; i++)
		st[i][0] = bal[i];

	for (int l = 1; l < LOGN; l++)
		for (int i = 0; i + (1 << l) <= n; i++)
			st[i][l] = min(st[i][l - 1], st[i + (1 << (l - 1))][l - 1]);

	for (int i = 0; i < n; i++)
	{
		int null_bal = 0;
		if (i != 0)
			null_bal = bal[i - 1];
		if (bal[i] < null_bal)
		{
			max_len[i] = 0;
			continue;
		}
		int l = i;
		int r = n + 1;
		while (r - l > 1)
		{
			int mid = (l + r) / 2;
			int mn = get_min(l, mid);
			if (mn >= null_bal)
				l = mid;
			else
				r = mid;
		}
		max_len[i] = l - i + 1;
	}

	int64 ans = 0;
	for (int i = 0; i <= n; i++)
	{
		int ind = arr[i];
		
		if (ind == n)
			continue;
		
		int pass = lcp[i];
		int start_from = ind + pass;
		int finish_to = ind + max_len[ind];

		int null_bal = 0;
		if (ind != 0)
			null_bal = bal[ind - 1];
		
		int cur_add = 0;
		if (bal_list.count(null_bal) == 1)
		{
			auto& l = bal_list[null_bal];
			auto it = lower_bound(l.begin(), l.end(), start_from);
			auto it2 = lower_bound(l.begin(), l.end(), finish_to);
			cur_add = it2 - it;
			cur_add = max(0, cur_add);
		}
		
		dbg(ind, cur_add, pass, start_from);
		ans += cur_add;
	}

	printf("%lld\n", ans);

	return 0;
}