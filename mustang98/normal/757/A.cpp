#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100005;

int main()
{
    //ifstream cin("input.txt");
    string s;
    cin >> s;
    int m[8] = {0};
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'B') m[0]++;
        else if (s[i] == 'u') m[1]++;
        else if (s[i] == 'l') m[2]++;
        else if (s[i] == 'b') m[3]++;
        else if (s[i] == 'a') m[4]++;
        else if (s[i] == 's') m[5]++;
        else if (s[i] == 'r') m[6]++;
    }

    int ans = 1e9;
    for (int i = 0; i < 7; ++i)
    {
        if (i == 1 || i == 4)
        {
            ans = min(ans, m[i] / 2);
        }
        else
        {
            ans = min(ans, m[i]);
        }
    }
    cout << ans;

    return 0;
}