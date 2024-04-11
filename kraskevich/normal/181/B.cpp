#include <algorithm>
#include <iostream>
using namespace std;

int cnt[2002][2002];

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    
    cin >> n;
    
    int x[n], y[n];
    
    for(int i = 0; i < 2002; ++i)
            for(int j = 0; j < 2002; ++j)
                    cnt[i][j] = 0;
                    
    for(int i = 0; i < n; ++i)
    {
            cin >> x[i] >> y[i];
            ++cnt[x[i] + 1000][y[i] + 1000];
    }
    
    long long ans = 0;
    
    for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j)
            {
                    int curX = x[i] + x[j], curY = y[i] + y[j];
                    if(curX % 2 || curY  % 2)
                            continue;
                    curX /= 2;
                    curY /= 2;
                    ans += (long long)cnt[curX + 1000][curY + 1000];
            }
    
    cout << ans;
    
    cin >> n;
    
    return 0;
}