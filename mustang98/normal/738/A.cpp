#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++)
    {
        if (i <= n - 3 && s[i] == 'o' && s[i + 1] == 'g' && s[i + 2] == 'o')
        {
            cout << "***";
            int j;
            for (j = i + 3; j <= n - 2; j+=2)
            {
                if (s[j] != 'g' || s[j + 1] != 'o')
                    break;
            }
            i = j - 1;
        }
        else
        {
            cout << s[i];
        }
    }
}