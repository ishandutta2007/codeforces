#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int r = 0;
        cin >> s;
        stack<int> cir, squ;
        for (int i = 0; i < s.length(); i++)
        {
            switch (s[i])
            {
            case '(':
                cir.push(0);
                break;
            case ')':
                if (!cir.empty() && cir.top() == 0)
                {
                    cir.pop();
                    r++;
                }
                else
                    cir.push(1);
                break;
            case '[':
                squ.push(0);
                break;
            case ']':
                if (!squ.empty() && squ.top() == 0)
                {
                    squ.pop();
                    r++;
                }
                else
                    squ.push(1);
            }
        }
        cout << r << '\n';
    }
}