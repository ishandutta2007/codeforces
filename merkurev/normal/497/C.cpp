#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;

struct Part
{
	int l, r, i;
	Part() : l(), r(), i() {}
	Part(int _l, int _r, int _i) : l(_l), r(_r), i(_i) {}
	bool operator < (const Part &A) const
	{
		return l < A.l;
	}
};
vector <Part> part;
struct Act
{
	int l, r, k, i;
	Act() : l(), r(), k(), i() {}
	Act(int _l, int _r, int _k, int _i) : l(_l), r(_r), k(_k), i(_i) {}
	bool operator < (const Act &A) const
	{
		if (r != A.r)
			return r < A.r;
		return i < A.i;
	}
};
vector <Act> act;

bool cmp(const Act &A, const Act &B)
{
	return A.l < B.l;
}

const int maxn = 1e5 + 100;
int ans[maxn];

int main()
{
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		part.push_back(Part(l, r, i) );
	}
	sort(part.begin(), part.end() );
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		act.push_back(Act(l, r, k, i) );
	}
	sort(act.begin(), act.end(), cmp);

	set <Act> acts;

	int ca = 0;
	for (int i = 0; i < n; i++)
	{
		int cl = part[i].l;
		while (ca < (int) act.size() && act[ca].l <= cl)
		{
			acts.insert(act[ca] );
			ca++;
		}
		auto it = acts.lower_bound(Act(0, part[i].r, 0, -1) );
		if (it == acts.end() )
		{
			printf("NO\n");
			return 0;
		}
		Act cur = *it;
		acts.erase(it);
		cur.k--;
		if (cur.k != 0)
			acts.insert(cur);
		ans[part[i].i] = cur.i;
	}
	printf("YES\n");
	for (int i = 0; i < n; i++)
		printf("%d ", ans[i] + 1);



	return 0;
}