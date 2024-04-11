#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<int> ve;

int main()
{
    cin >> n >> s;
    for (char &c : s)
        if (c == '(')
            ve.push_back(1);
        else
        {
            if (ve.empty() || ve.back() == -1)
                ve.push_back(-1);
            else
                ve.pop_back();
        }
    if (ve.size() == 0 || (ve.size() == 2 && ve[0] == -1 && ve[1] == 1))
        cout << "Yes\n";
    else
        cout << "No\n";
}