#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


struct Boy
{
	int v, d, p, id;

	Boy() : v(), d(), p(), id() {}

	void scare(int x)
	{
		p = max(-10, p - x);
	}
	void read(int _id)
	{
		id = _id;
		scanf("%d%d%d", &v, &d, &p);
	}

};


vector <Boy> boy;

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		boy.push_back(Boy() );
		boy[i].read(i);
	}
	vector <int> ans;

	while (!boy.empty() )
	{
		Boy fst = boy[0];
		ans.push_back(fst.id);
		boy.erase(boy.begin() );
		for (int i = 0; i < fst.v && i < (int) boy.size(); i++)
		{
			boy[i].scare(fst.v - i);
		}
		for (int i = 0; i < (int) boy.size(); i++)
		{
			Boy cur = boy[i];
			if (cur.p >= 0)
				continue;
			boy.erase(boy.begin() + i);
			for (int j = i; j < (int) boy.size(); j++)
			{	
				boy[j].scare(cur.d);
			}
			i--;
		}
	}

	printf("%d\n", (int) ans.size() );
	for (auto id : ans)
		printf("%d ", id + 1);
	
	return 0;
}