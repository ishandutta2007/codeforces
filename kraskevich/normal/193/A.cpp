#include <iostream>
#include <vector>
#include <string>
using namespace std;

void dfs(int i, int j, vector <vector <bool> > & u, vector <string> & s, int delx, int dely)
{
     if(i == delx && j == dely)
        return; 
     u[i][j] = true;
     if(i - 1 >= 0 && s[i - 1][j] == '#' && !u[i - 1][j])
          dfs(i - 1, j, u, s, delx, dely);
     if(i + 1 < s.size() && s[i + 1][j] == '#' && !u[i + 1][j])
          dfs(i + 1, j, u, s, delx, dely);
     if(j - 1 >= 0 && s[i][j - 1] == '#' && !u[i][j - 1])
          dfs(i, j - 1, u, s, delx, dely);
     if(j + 1 < s[0].length() && s[i][j + 1] == '#' && !u[i][j + 1])
          dfs(i, j + 1, u, s, delx, dely);
}

bool check(int delx, int dely, vector <string> & s)
{
    vector <vector <bool> > u(s.size(), vector <bool> (s[0].length(), false));
        
    bool done = false;
    for(int i = 0; i < s.size() && !done; ++i)
        for(int j = 0; j < s[0].length() && !done; ++j)
            if(s[i][j] == '#' && (i != delx || j != dely))
            {
                dfs(i, j, u, s, delx, dely);
                done = true;
            }
    
    bool ok = false;
    for(int i = 0; i < s.size(); ++i)
        for(int j = 0; j < s[0].length(); ++j)
            if(s[i][j] == '#' && !u[i][j] && (i != delx || j != dely))
                ok = true;
    
    return ok;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    
    vector <string> s(n);
    for(int i = 0; i < n; ++i)
        cin >> s[i];
    
    int cnt = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(s[i][j] == '#')
                cnt++;
    if(cnt <= 2)
    {
        cout << -1;
        return 0;
    }
    
    bool one = false;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(s[i][j] == '#' && check(i, j, s))
                one = true;
    
    cout << (one ? 1 : 2) << endl;
    
    return 0;
}