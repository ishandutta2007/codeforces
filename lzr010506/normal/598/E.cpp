#include <bits/stdc++.h>
#define FOR(i, x, y) for(int (i) = (x); (i) <= (y); i ++)
#define pii pair<int, int>
using namespace std;
const int INF = INT_MAX / 10;
int F[31][31][51];

void Init()
{
	FOR(r, 1, 30)
    	FOR(c, 1, 30)
    		FOR(k, 1, 50)
            {
                F[r][c][k] = INF;
                if (r * c < k) F[r][c][k] = INF;
                else if (k == 0) F[r][c][k] = 0;
                else if (r * c == k) F[r][c][k] = 0;
                else 
                {
                    FOR(R, 1, r - 1)//get C
                    	FOR(K, 0, k)
                            F[r][c][k] = min(F[r][c][k], F[R][c][K] + F[r - R][c][k - K] + c * c);
                    FOR(C, 1, c - 1)//get R
                    	FOR(K, 0, k)
                            F[r][c][k] = min(F[r][c][k], F[r][C][K] + F[r][c - C][k - K] + r * r);
                }
            }
}

int main() 
{
    Init();
    int T, n, m, k;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d %d %d", &n, &m, &k);
        printf("%d\n", F[n][m][k]);
    }
    return 0;
}