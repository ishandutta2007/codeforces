#include <bits/stdc++.h>

#define S second
#define F first

using namespace std;
typedef long long ll;

vector<int> ans;

int main()
{
    int a, b, c;
    int m[1000], m1[1000];
    int n;
    cin >> n;
    string s;
    cin >> s;
    a = 0;
    b = 0;
    for(int i = 0; i < n;i++)
    {
        if (s[i] == 'x') a++;
        else b++;
    }
    if (a < b)
    {
        int ans = n / 2 - a;
        cout << ans << endl;
        for (int i = 0;i < n; i++)
        {
            if (!ans) break;
            if (s[i] == 'X')
            {
                s[i] = 'x';
                ans--;
            }
        }
    }
    else if (b < a)
    {
        int ans = n / 2 - b;
        cout << ans << endl;
        for (int i = 0;i < n; i++)
        {
            if (!ans) break;
            if (s[i] == 'x')
            {
                s[i] = 'X';
                ans--;
            }
        }
    }
    else
    {
        cout << 0 << endl;
    }
    cout << s;
}