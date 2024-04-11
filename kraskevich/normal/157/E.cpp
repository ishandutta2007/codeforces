#include <iostream>
#include <string>
using namespace std;

const int mod = (int)1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    
    int f[101][3000];
    for(int i = 0; i <= 100; ++i)
            for(int j = 0; j < 3000; ++j)
                    f[i][j] = 0;
    for(int i = 0; i < 26; ++i)
            f[0][i] = 1;
    for(int i = 0; i < 100; ++i)
            for(int c = 0; c < 26; ++c)
                    for(int s = 0; s < 2600; ++s)
                            f[i + 1][s + c] += f[i][s], f[i + 1][s + c] %= mod;
    
    int t;
    cin >> t;
    
    for(int i = 0; i < t; ++i)
    {
            string cur;
            cin >> cur;
            
            int n = cur.length(), s = 0;
            for(int i = 0; i < n; ++i)
                    s += (int)cur[i] - 'a';
            
            cout << f[n - 1][s] - 1 << endl;
    }
    
    cin >> t;
    return 0;
}