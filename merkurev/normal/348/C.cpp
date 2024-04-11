#include <iostream>
#include <vector>
using namespace std;



long long a[100500];
vector <int> S[100500];

vector <int> inBig[100500];
int bigId[100500];

int BBInter[320][320];
int SBInter[100100][320];
int bi = 0;

int sq = 320;
//int sq = 1;

long long bigSum[320];
long long bigAdd[320];


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i] );
	for (int i = 0; i < m; i++)
	{
		bigId[i] = -1;
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			int x;
			scanf("%d", &x);
			x--;
			S[i].push_back(x);
		}
		if (k < sq)
			continue;
		bigId[i] = bi;
		for (int j = 0; j < k; j++)
		{
			int cur = S[i][j];
			inBig[cur].push_back(bi);
			bigSum[bi] += a[cur];
		}
		BBInter[bi][bi] = k;
		bi++;
	}
	for (int i = 0; i < n; i++)
		for (int a = 0; a < inBig[i].size(); a++)
			for (int b = a + 1; b < inBig[i].size(); b++)
			{
				int A = inBig[i][a], B = inBig[i][b];
				BBInter[A][B]++;
				BBInter[B][A]++;
			}
	for (int i = 0; i < n; i++)
	{
		if (bigId[i] != -1)
			continue;
		for (int j = 0; j < S[i].size(); j++)
		{
			int cur = S[i][j];
			for (int h = 0; h < inBig[cur].size(); h++)
				SBInter[i][inBig[cur][h] ]++;
		}
	}

	for (int t = 0; t < q; t++)
	{
		char c[2];
		scanf("%s", c);
		if (c[0] == '?')
		{
			int id;
			scanf("%d", &id);
			id--;

			if (bigId[id] != -1)
			{
				id = bigId[id];
				printf("%I64d\n", bigSum[id] );
			}
			else
			{
				long long ans = 0;
				for (int i = 0; i < S[id].size(); i++)
				{
					ans += a[S[id][i] ];
				}
				for (int j = 0; j < bi; j++)
				{
					ans += bigAdd[j] * SBInter[id][j];
				}
				printf("%I64d\n", ans);
			}
		}
		if (c[0] == '+')
		{
			int id, val;
			scanf("%d%d", &id, &val);
			id--;

			if (bigId[id] != -1)
			{
				id = bigId[id];
				bigAdd[id] += val;
				for (int i = 0; i < bi; i++)
					bigSum[i] += val * 1LL * BBInter[id][i];
			}
			else
			{
				for (int i = 0; i < bi; i++)
					bigSum[i] += val * 1LL * SBInter[id][i];
				for (int i = 0; i < S[id].size(); i++)
					a[S[id][i] ] += val;
			}
		}
	}



	return 0;
}