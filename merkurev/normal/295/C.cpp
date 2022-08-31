#include <iostream>
using namespace std;


#define triple pair<int, pair<int, int> >
#define make_triple(a, b, c) make_pair(a, make_pair(b, c) )
#define FST first
#define SCD second.first
#define THR second.second


pair <int, long long> dp[2][55][55];
bool reach[2][55][55];

triple qu[100500];
long long C[55][55];

long long mod = 1e9 + 7;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    for (int i = 0; i < 55; i++)
	{
        C[i][0] = 1;
        C[i][i] = 1;
        for (int j = 1; j < i; j++)
		{
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1] ) % mod;
		}
	}



    int n, k;
    int cnt50 = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
	{
        int w = 50;
        scanf("%d", &w);
        if (w == 50)
            cnt50++;
	}
    int cnt100 = n - cnt50;
    
    for (int  i = 0; i < 2; i++)
        for (int h = 0; h <= 55; h++)
            for (int j = 0; j <= 55; j++)
                dp[i][h][j] = make_pair(-1, 0);

	int l = 0, r = 0;
    dp[0][n][cnt50] = make_pair(0, 1);
    qu[r++] = make_triple(0, n, cnt50);
   
	
	while (r > l)
	{
        triple cur = qu[l++];
		int curd = dp[cur.FST][cur.SCD][cur.THR].first;
		long long curnum = dp[cur.FST][cur.SCD][cur.THR].second;

        int numH = cur.SCD - cur.THR, numL = cur.THR;
        if (cur.FST == 1)
		{
            numH = cnt100 - numH;
            numL = cnt50 - numL;
		}
        int sgn = 1;
        if (cur.FST == 1)
            sgn = -1;
        for (int a = 0; a <= numL; a++)
            for (int b = 0; b <= numH; b++)
			{
                if (a + b == 0)
                    continue;
                if (a * 50 + b * 100 > k)
                    continue;

                long long NUM = ( (C[numL][ a] * C[numH][ b] ) % mod * curnum) % mod;

                triple nx = make_triple(cur.FST ^ 1, cur.SCD - sgn * (a + b), cur.THR - sgn * a);
                if (dp[nx.FST][nx.SCD][nx.THR].first == -1)
				{
                    dp[nx.FST][nx.SCD][nx.THR] = make_pair(curd + 1, 0);
                    qu[r++] = nx;
				}
                if (dp[nx.FST][nx.SCD][nx.THR].first == curd + 1)
				{
					dp[nx.FST][nx.SCD][nx.THR].second += NUM;
                    dp[nx.FST][nx.SCD][nx.THR].second %= mod;
				}
			}
	}

	printf("%d\n%I64d", dp[1][0][0].first, dp[1][0][0].second);

    return 0;
}