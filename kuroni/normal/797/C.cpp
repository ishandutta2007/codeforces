#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

char mini[100005];
string s, ans = "";
vector <char> kay;
int i, n;

int main()
{
    cin >> s;
    n = s.size();
    mini[n] = 'z';
    for (i = n - 1; i >= 0; i--)
        mini[i] = min(mini[i + 1], s[i]);
    for (i = 0; i < n; i++)
    {
        kay.push_back(s[i]);
        while (!kay.empty())
        {
            if (kay.back() <= mini[i + 1])
            {
                ans += kay.back();
                kay.pop_back();
            }
            else break;
        }
    }
    printf("%s", ans.c_str());
}