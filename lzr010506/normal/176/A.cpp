#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
int DP[105][105], N, M, K, B[15][105], aa[15][105], pp[15][105];

int solve(int a, int b)
{
    FOR(i, 0, M + 1) 
    	FOR(j, 0, K) 
    		DP[i][j] = 0;
    FOR(i, 0, M) 
    	FOR(k, 0, K)
        	FOR(P, 0, pp[a][i])
        	{
            	if(k + P > K) continue;
            	int Nk = k + P;
            	int Np = DP[i][k] + aa[b][i] * P - B[a][i] * P;
            	DP[i+1][Nk] = max(DP[i + 1][Nk], Np);
        	}
    int ret = 0;
    FOR(i, 0, K) 
    	ret = max(ret, DP[M + 1][i]);
    return ret;
}

int main()
{
    cin >> N >> M >> K;
    FOR(i, 1, N)
    {
        string name;
        cin >> name;
        FOR(j, 1, M) 
        	cin >> B[i][j] >> aa[i][j] >> pp[i][j];
    }
    int ans = 0;
    FOR(i, 1, N) 
    	FOR(j, 1, N) 
    		if(i != j) ans = max(ans, solve(i,j));
    cout << ans;
    return 0;
}