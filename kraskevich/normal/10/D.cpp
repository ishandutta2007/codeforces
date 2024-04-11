#include <iostream>
#include <vector>
using namespace std;

#define pii pair<int, int>

pii p[501][501];

void print(int i, int j, int a[], int b[])
{
     if(!i || !j)
           return;
     print(p[i][j].first, p[i][j].second, a, b);
     if(a[i - 1] == b[j - 1])
            cout << a[i - 1] << " ";
}

int main()
{
    int n;
    
    cin >> n;
    
    int a[n];
    
    for(int i = 0; i < n; ++i)
            cin >> a[i];
    
    int m;
    
    cin >> m;
    
    int b[m];
    
    for(int i = 0; i < m; ++i)
            cin >> b[i];
    
    int f[n + 1][m + 1];
    
    for(int i = 0; i <= n; ++i)
            f[i][0] = 0, p[i][0] = pii(0, 0);
    for(int j = 0; j <= m; ++j)
            f[0][j] = 0, p[0][j] = pii(0, 0);
            
    vector<int> val, len, ii, jj;
    int res = 0, resi = 0, resj = 0;
    
    for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
            {
                    if(a[i - 1] != b[j - 1])
                           if(f[i - 1][j] > f[i][j - 1])
                           {
                                  p[i][j] = p[i - 1][j];
                                  f[i][j] = f[i - 1][j];
                           }
                           else
                           {
                               p[i][j] = p[i][j - 1];
                               f[i][j] = f[i][j - 1];
                           }
                    else
                    {
                        int cur = -1;
                        for(int k = 0; k < val.size(); ++k)
                                if(val[k] < a[i - 1] && (cur < 0 || len[cur] < len[k]) && ii[k] <= i && jj[k] <= j)
                                          cur = k;
                        if(cur < 0)
                        {
                               f[i][j] = 1;
                               p[i][j] = pii(0, 0);
                               val.push_back(a[i - 1]);
                               len.push_back(f[i][j]);
                               ii.push_back(i);
                               jj.push_back(j);
                        }
                        else
                        {
                            f[i][j] = len[cur] + 1;
                            p[i][j] = pii(ii[cur], jj[cur]);
                            val.push_back(a[i - 1]);
                            len.push_back(f[i][j]);
                            ii.push_back(i);
                            jj.push_back(j);
                        }
                        if(res < f[i][j])
                               res = f[i][j], resi = i, resj = j;
                    }
            }
    
    cout << res << endl;                             
    print(resi, resj, a, b);
             
    cin >> n;
    
    return 0;
}