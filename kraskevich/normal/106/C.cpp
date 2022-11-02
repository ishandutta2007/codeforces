#include <vector>
#include <iostream>
using namespace std;

vector<vector<int> > f;

void solve(int t, int n, int alln, int cost)
{
     vector<int> curf(1001, 0);
     for(int j = 1;; ++j)
     {
           if(j * n > alln || j * t > 1000)
                break;
           curf[j * t] = j * cost;
     }
     f.push_back(curf);
}

int sum[11][1001];

int calc(int n)
{
    for(int i = 0; i < 11; ++i)
            for(int j = 0; j < 1001; ++j)
                    sum[i][j] = 0;
    for(int i = 0; i < 1001; ++i)
            sum[0][i] = f[0][i];
    for(int i = 1; i < f.size(); ++i)
            for(int j = 0; j <= 1000; ++j)
                    for(int prev = 0; prev <= j; ++prev)
                            sum[i][j] = max(sum[i][j], sum[i - 1][prev] + f[i][j - prev]);
    
    int ans = 0;
    for(int i = 0; i <= n; ++i)
            ans = max(ans, sum[f.size() - 1][i]);
    
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, m, c, d;
    cin >> n >> m >> c >> d;
    
    solve(c, 0, 0, d);
    
    for(int i = 0; i < m; ++i)
    {
            int a, b;
            cin >> a >> b >> c >> d;
            solve(c, b, a, d);
    }
    
    cout << calc(n) << endl;
    
    cin >> n;
    
    return 0;
}