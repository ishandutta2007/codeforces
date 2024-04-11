#include <vector>
#include <set>
#include <iostream>
using namespace std;

#define pii pair<int, int>
pii was[1500][1500];
string s[1500];
bool ok = false;
int n, m;

void dfs(int i, int j)
{
    if(s[i % n][j % m] != '.')
        return;
    if(ok)
        return;
        
    if(was[i % n][j % m] != pii(-1, -1))
    {
        if(was[i % n][j % m] != pii(i, j))
            ok = true;
        return;
    }
    
    was[i % n][j % m] = pii(i, j);
    
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> s[i];
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            was[i][j] = pii(-1, -1);
       
    int x, y;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(s[i][j] == 'S')
            {
                x = i;
                y = j;
                s[i][j] = '.';
            }
    
    x += 2000 * n;
    y += 2000 * m;
    
    dfs(x, y);
    
    cout << (ok ? "Yes" : "No") << endl;
    
    cin >> n;
    
    return 0;
}