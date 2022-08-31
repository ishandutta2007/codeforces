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
	#define debug_flag true
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

const int K = 5;
const int N = (int) 1.5e5 + 1e4;
const int BLOCK_SIZE = 3000;
const int BLOCK_CNT = (N + BLOCK_SIZE - 1) / BLOCK_SIZE; 


int listSz;
int owner[N];
int timerBlock[BLOCK_CNT];
int timerInBlock[BLOCK_CNT][N];
int timerInTop[BLOCK_CNT][N];
int cntInBlock[BLOCK_CNT][N];
int ownerBlock[BLOCK_CNT];
int blockTop[BLOCK_CNT][K][2];
int answer[N];
int used[N];
int timer = 146;
const int INF = (int) 1e9 + 100;

int n, p;

void pushBlock(int id)
{
	if (ownerBlock[id] == -1) return;
	int start = id * BLOCK_SIZE;
	for (int i = 0; i < BLOCK_SIZE; i++)
		owner[start + i] = ownerBlock[id];
	ownerBlock[id] = -1;
}

pair <int, int> vvv[BLOCK_SIZE];
int list[BLOCK_SIZE];

void updateBlock(int id)
{
	timerBlock[id]++;
	listSz = 0;
	int start = id * BLOCK_SIZE;
	for (int i = 0; i < BLOCK_SIZE; i++)
	{
		int x = owner[start + i];
		if (timerInBlock[id][x] != timerBlock[id] )
		{
			timerInBlock[id][x] = timerBlock[id];
			cntInBlock[id][x] = 0;
			list[listSz++] = x;
		}
		cntInBlock[id][x]++;
	}
	for (int i = 0; i < listSz; i++)
		vvv[i] = make_pair(cntInBlock[id][list[i] ], list[i] );
	int cnt = min(5, listSz);
	nth_element(vvv, vvv + listSz - cnt, vvv + listSz);
	reverse(vvv, vvv + listSz);
	memset(blockTop[id], 0, sizeof blockTop[id] );
	for (int i = 0; i < cnt; i++)
	{
		timerInTop[id][vvv[i].second] = timerBlock[id];
		blockTop[id][i][0] = vvv[i].second;
		blockTop[id][i][1] = vvv[i].first;
	}
}

void setOwner(int l, int r, int id)
{
	int lBlock = l / BLOCK_SIZE, rBlock = r / BLOCK_SIZE;
	pushBlock(lBlock);
	pushBlock(rBlock);
	
	if (lBlock == rBlock)
	{
		for (int i = l; i <= r; i++)
			owner[i] = id;
	}
	else
	{
		int lBEnd = (lBlock + 1) * BLOCK_SIZE;
		for (int i = l; i < lBEnd; i++)
			owner[i] = id;
		int rStart = rBlock * BLOCK_SIZE;
		for (int i = rStart; i <= r; i++)
			owner[i] = id;
	}
	updateBlock(lBlock);
	if (lBlock != rBlock)
		updateBlock(rBlock);
	for (int i = lBlock + 1; i < rBlock; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			blockTop[i][j][0] = id;
			blockTop[i][j][1] = 0;
		}
		blockTop[i][0][1] = BLOCK_SIZE;
		ownerBlock[i] = id;
		timerBlock[i]++;
		timerInTop[i][id] = timerBlock[i];
		cntInBlock[i][id] = BLOCK_SIZE;
		timerInBlock[i][id] = timerBlock[i];
	}
}

void init()
{
	memset(ownerBlock, -1, sizeof ownerBlock);
	for (int i = 0; i < n; i += BLOCK_SIZE)
		updateBlock(i / BLOCK_SIZE);
}


bool test(int l, int r, int id, int need)
{
//	eprintf("l = %d, r = %d, id = %d, need = %d\n", l, r, id, need);
	int lBlock = l / BLOCK_SIZE, rBlock = r / BLOCK_SIZE;

	for (int i = lBlock + 1; i < rBlock; i++)
	{
		if (timerInBlock[i][id] == timerBlock[i] && timerInTop[i][id] != timerBlock[i] )
			need -= cntInBlock[i][id];
	}
	return need <= 0;
}

void solve(int l, int r)
{
	int need = (r - l + 1 + 29) / 30;
	int realNeed = ( (r - l + 1) * p + 99) / 100;
	timer++;
	int lBlock = l / BLOCK_SIZE, rBlock = r / BLOCK_SIZE;
	pushBlock(lBlock);
	pushBlock(rBlock);
	listSz = 0;
	
	if (lBlock == rBlock)
	{
		for (int i = l; i <= r; i++)
		{
			int x = owner[i];
			if (used[x] != timer)
			{
				used[x] = timer;
				answer[x] = 0;
			}
			answer[x]++;
			if (answer[x] >= need)
			{
				answer[x] -= INF;
				list[listSz++] = x;
			}
		}
	}
	else
	{
		int lBEnd = (lBlock + 1) * BLOCK_SIZE;
		for (int i = l; i < lBEnd; i++)
		{
			int x = owner[i];
			if (used[x] != timer)
			{
				used[x] = timer;
				answer[x] = 0;
			}
			answer[x]++;
			if (answer[x] >= need)
			{
				answer[x] -= INF;
				list[listSz++] = x;
			}
		}
		int rStart = rBlock * BLOCK_SIZE;
		for (int i = rStart; i <= r; i++)
		{
			int x = owner[i];
//			eprintf("x = %d\n", x);
			if (used[x] != timer)
			{
				used[x] = timer;
				answer[x] = 0;
			}
			answer[x]++;
			if (answer[x] >= need)
			{
				answer[x] -= INF;
				list[listSz++] = x;
			}
		}
	}
	for (int i = lBlock + 1; i < rBlock; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int x = blockTop[i][j][0];
			int cnt = blockTop[i][j][1];
			if (used[x] != timer)
			{
				used[x] = timer;
				answer[x] = 0;
			}
			answer[x] += cnt;
			if (answer[x] >= need)
			{
				answer[x] -= INF;
				list[listSz++] = x;
			}
		}
	}
	if (listSz > 30) throw;
	vector <int> ans;
	vector <pair <int, int> > lll;
	for (int i = 0; i < listSz; i++)
		lll.emplace_back(answer[list[i] ] + INF, list[i] );
	sort(lll.begin(), lll.end() );
	reverse(lll.begin(), lll.end() );
	int rem = (r - l + 1);
	for (auto pp : lll)
	{
		rem -= pp.first;
		if (pp.first + rem < realNeed) continue;
		if (pp.first >= realNeed || test(l, r, pp.second, realNeed - pp.first) )
			ans.push_back(pp.second);
	}
	printf("%d", (int) ans.size() );
	for (int x : ans)
		printf(" %d", x + 1);
	printf("\n");
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	int m;
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &owner[i] );
		owner[i]--;
	}
	init();

	for (int it = 0; it < m; it++)
	{
		int type;
		scanf("%d", &type);
		if (type == 1)
		{
			int l, r, id;
			scanf("%d%d%d", &l, &r, &id);
			l--;
			r--;
			id--;
			setOwner(l, r, id);
		}
		else
		{
			int l, r;
			scanf("%d%d", &l, &r);
			l--;
			r--;
			solve(l, r);
		}
	}


	return 0;
}