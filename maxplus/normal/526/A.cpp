#include <iostream>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    for (int st = 0; st < n; ++st)
    {
        for (int l = 1; l < n; ++l)
            for (int t = 0; st + l * t < n; ++t)
            {
                if (s[st + l * t] == '.')
                    break;
                if (t == 4)
                {
                    cout << "yes";
                    return 0;
                }
            }
    }
    cout << "no";
    return 0;
}