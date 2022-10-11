#include <bits/stdc++.h>
using namespace std;

string s, t;
vector<int> ve;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        t.push_back('0');
        if (s[i] == '0')
        {
            if (!ve.empty())
            {
                t[ve.back()] = '1';
                ve.pop_back();
            }
        }
        else
            ve.push_back(i);
    }
    cout << t;
}