#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map <int, vector<pair<int, int> > > H, V;


void addH(int h, int a, int b)
{
	if (H.count(h) != 0)
	{
		H[h].push_back(make_pair(a, b) );
		return;
	}
	vector <pair<int, int> > v;
	v.push_back(make_pair(a, b) );
	H[h] = v;
}
void addV(int h, int a, int b)
{
	if (V.count(h) != 0)
	{
		V[h].push_back(make_pair(a, b) );
		return;
	}
	vector <pair<int, int> > v;
	v.push_back(make_pair(a, b) );
	V[h] = v;
}


int getAns(vector <pair<int, int> > v, int Len)
{
	vector <pair<int, int> > ev;
	for (int i = 0; i < v.size(); i++)
	{
		ev.push_back(make_pair(v[i].first, 1) );
		ev.push_back(make_pair(v[i].second, -1) );
	}
	int prv = 0;
	int cnt = 0;
	int ans = 0;
	sort(ev.begin(), ev.end() );
	for (int i = 0; i < ev.size(); i++)
	{
		int cur = ev[i].first;
		if (cnt == 0)
			ans += cur - prv;
		prv = cur;
		cnt += ev[i].second;
	}
	if (cnt != 0)
		throw 42;
	ans += Len - prv;
	return ans;
}

void printAns(int a, int b, int d, bool flag)
{
	int c = a;
	if (flag)
	{
		swap(a, b);
		swap(c, d);
	}
	printf("%d %d %d %d", a, b, c, d);
}

void makeAns(int h, vector <pair<int, int> > v, int Len, bool flag)
{
	vector <pair<int, int> > ev;
	for (int i = 0; i < v.size(); i++)
	{
		ev.push_back(make_pair(v[i].first, 1) );
		ev.push_back(make_pair(v[i].second, -1) );
	}
	int prv = 0;
	int cnt = 0;
	int ans = 0;
	sort(ev.begin(), ev.end() );
	for (int i = 0; i < ev.size(); i++)
	{
		int cur = ev[i].first;
		if (cnt == 0)
			ans += cur - prv;
		prv = cur;
		cnt += ev[i].second;
		if (ans >= Len)
			break;
	}
	if (ans < Len)
	{
		prv += Len - ans;
		ans = Len;
	}
	printAns(h, 0, prv - (ans - Len), flag);
}

int main()
{

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);

	for (int i = 0; i < k; i++)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if (c < a)
			swap(a, c);
		if (d < b)
			swap(b, d);
		if (a == c)
		{
			addH(a, b, d);
		}
		else if (b == d)
		{
			addV(b, a, c);
		}
	}
	int cntH = n - 1 - H.size();
	int cntV = m - 1 - V.size();
	if (cntH % 2 != 0)
	{
		for (int i = 1; i < n; i++)
			if (H.count(i) == 0)
			{
				addH(i, 0, 0);
				break;
			}
	}
	if (cntV % 2 != 0)
	{
		for (int i = 1; i < m; i++)
			if (V.count(i) == 0)
			{
				addV(i, 0, 0);
				break;
			}
	}

	map<int, vector <pair<int, int> > >::iterator it;
	int ANS = 0;
	vector <pair<int, int> > HOR, VER;
	for (it = H.begin(); it != H.end(); it++)
	{
		vector <pair<int, int> > v = it->second;
		int hor = it->first;
		int cur = getAns(v, m);
		ANS ^= cur;
		HOR.push_back(make_pair(hor, cur) );
	}
	for (it = V.begin(); it != V.end(); it++)
	{
		vector <pair<int, int> > v = it->second;
		int ver = it->first;
		int cur = getAns(v, n);
		ANS ^= cur;
		VER.push_back(make_pair(ver, cur) );
	}

	if (ANS == 0)
	{
		printf("SECOND");
		return 0;
	}
	printf("FIRST\n");
	for (int i = 0; i < HOR.size(); i++)
	{
		int cur = HOR[i].second;
		if ( (ANS ^ cur) > cur)
			continue;
		makeAns(HOR[i].first, H[HOR[i].first ], cur - (ANS ^ cur), false);
		return 0;
	}
	for (int i = 0; i < VER.size(); i++)
	{
		int cur = VER[i].second;
		if ( (ANS ^ cur) > cur)
			continue;
		makeAns(VER[i].first, V[VER[i].first ], cur - (ANS ^ cur), true);
		return 0;
	}
	throw 42;
	return 0;
}