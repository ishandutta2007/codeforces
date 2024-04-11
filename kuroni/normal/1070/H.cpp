#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

const int N = 10005;

int n, q;
string que, s[N];
map<string, vector<int>> ma;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < s[i].size(); j++)
        {
            string t = "";
            for (int k = j; k < s[i].size(); k++)
            {
                t += s[i][k];
                if (ma[t].empty() || ma[t].back() != i)
                    ma[t].push_back(i);
            }
        }
    }
    cin >> q;
    while (q--)
    {
        cin >> que;
        if (ma.find(que) == ma.end())
            cout << "0 -\n";
        else
            cout << ma[que].size() << " " << s[ma[que].back()] << '\n';
    }
}