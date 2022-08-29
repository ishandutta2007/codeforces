#include <vector>
#include <iostream>
#include <algorithm>
using namespace  std;

vector <pair<int, int> > a[100500];
vector <int> good;
vector <int> isIn[100500];
int cntBad[100500];
int fst[100500];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);


	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x;
			scanf("%d", &x);
			if (x == -1)
				continue;
			isIn[j].push_back(i);
			a[i].push_back(make_pair(x, j) );
		}
		sort(a[i].begin(), a[i].end() );
		for (int j = 1; j < a[i].size(); j++)
		{
			if (a[i][j].first != a[i][0].first )
				cntBad[a[i][j].second ]++;
		}
	}

	for (int i = 0; i < m; i++)
		if (cntBad[i] == 0)
		{
			good.push_back(i);
			cntBad[i] = -1;
		}
	int l = 0;
	while (l < good.size() )
	{
		int cur = good[l++];
		int len = isIn[cur].size();
		for (int j = 0; j < len; j++)
		{
			int row = isIn[cur][j];
			int curFst = fst[row];
			if (a[row].size() - curFst < 2 || a[row][curFst].first == a[row][curFst + 1].first )
			{
				fst[row]++;
				continue;
			}
			fst[row]++;
			curFst++;
			int curVal = a[row][curFst].first;
			for (; curFst < a[row].size(); )
			{
				if (a[row][curFst].first != curVal)
				{
					curFst--;
					break;
				}
				int c = a[row][curFst].second;
				cntBad[c]--;
				if (cntBad[c] == 0)
				{
					cntBad[c] = -1;
					good.push_back(c);
				}
				curFst++;
			}
		}
	}
	if (good.size() != m)
	{
		printf("-1");
		return 0;
	}
	for (int i = 0; i < good.size(); i++)
		printf("%d ", good[i] + 1);

	return 0;
}