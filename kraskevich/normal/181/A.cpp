#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, m;
    
    cin >> n >> m;
    
    string s[n];
    
    for(int i = 0; i < n; ++i)
            cin >> s[i];
    
    int x = 0, y = 0;
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                    if(s[i][j] == '*')
                               x ^= (i + 1),y ^= (j + 1);
    
    cout << x << " " << y << endl;
    
    cin >> n;
    
    return 0;
}