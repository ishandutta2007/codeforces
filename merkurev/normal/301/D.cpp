#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector <pair<int, int> > v;
vector <pair<pair<int, int>, int> > querry, events;
int a[200500];
int rev[200500];
int answer[200500];
int firstIn[200500];
int quAt[200500];

const int ST = 19;
const int SZ = (1 << ST);

int value[SZ * 2 + 5];


int getValue(int pos)
{
	pos += SZ;
	int ans = 0;
	while (true)
	{
		ans += value[pos];
		if (pos == 1)
			break;
		pos >>= 1;
	}
	return ans;
}
void setZero(int pos)
{
	pos += SZ;
	int a = pos;
	int ans = 0;
	value[pos] = 0;

	while (true)
	{
		ans += value[pos];
		if (pos == 1)
			break;
		pos >>= 1;
	}
	value[a] = -ans;
}

void addOnSegment(int v, int a, int b, int l, int r)
{
	if (a <= l && b >= r)
	{
		value[v] ++;
		return;
	}
	if (a > r || b < l)
	{
		return;
	}
	addOnSegment(v * 2, a, b, l, l + (r - l + 1) / 2 - 1);
	addOnSegment(v * 2 + 1, a, b, l + (r - l + 1) / 2, r);
}

void addOneOnSuffix(int from)
{
	addOnSegment(1, from, SZ - 1, 0, SZ - 1);
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//int N = 2500;//200500
	int N = 200500;
	int cnt = 0;

	v.resize(N * 15);
	int VV = 0;
	for (int i = 1; i <= N; i++)
	{
		int x = i;
		for (int j = 1; x <= N; j++)
		{
			v[VV++] = make_pair(i, x);
			x += i;
			cnt++;
		}
	}
	v.resize(VV);
	//printf("%d\n", cnt);

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", &a[i] );
		rev[a[i] ] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		querry.push_back(make_pair(make_pair(y, x), i) );
	}
	sort(querry.begin(), querry.end() );

	int sz = querry.size();
	int curMaxY = -1;
	for (int i = 0; i < sz; i++)
	{
		int x = querry[i].first.second;
		int y = querry[i].first.first;
		for (int j = curMaxY + 1; j <= y; j++)
		{
			firstIn[j] = i;
			curMaxY = y;
		}
		events.push_back(make_pair(make_pair(x, 0), i) );
		events.push_back(make_pair(make_pair(y, 2), i) );
		quAt[i] = querry[i].second;
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].second > n)
			continue;
		int aa = rev[v[i].first];
		int bb = rev[v[i].second];
		int a = min(aa, bb);
		int b = max(aa, bb);
		events.push_back(make_pair(make_pair(a, 1), b) );
	}
	sort(events.begin(), events.end() );

	for (int i = 0; i < events.size(); i++)
	{
		int type = events[i].first.second;
		int a = events[i].first.first;
		int b = events[i].second;


		if (type == 0)
		{
			setZero(b);
			continue;
		}
		if (type == 2)
		{
			answer[quAt[b] ] = getValue(b);
			continue;
		}
		if (type == 1)
		{
			int x = firstIn[b];
			addOneOnSuffix(x);
		}
	}

	for (int i = 0; i < m; i++)
	{
		printf("%d\n", answer[i] );
	}


	return 0;
}