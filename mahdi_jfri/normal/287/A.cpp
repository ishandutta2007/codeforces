#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
string s[4];
int main()
{
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int x = (s[i][j] != s[i][j + 1]) + (s[i][j] != s[i + 1][j]) + (s[i][j] != s[i + 1][j + 1]);
            if(x <= 1 || x == 3)
            {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}