#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

string s[100], res;
vector<int> e[26];
queue<int> q;
int n, deg[26];

int main()
{

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j <= min(s[i].length(), s[i + 1].length()); j++)
            if (s[i][j] != s[i + 1][j])
            {
                if (j == min(s[i].length(), s[i + 1].length()))
                {
                    if (s[i].length() > s[i + 1].length())
                        deg[0] += 100000000;
                    break;
                }

                e[s[i][j] - 'a'].emplace_back(s[i + 1][j] - 'a');
                deg[s[i + 1][j] - 'a']++;
                break;
            }

    for (int i = 0; i < 26; i++)
        if (!deg[i])
            q.push(i);
    while (!q.empty())
    {
        res = res + (char)('a' + q.front());
        for (auto i : e[q.front()])
        {
            deg[i]--;
            if (!deg[i])
                q.push(i);
        }
        q.pop();
    }
    if (res.length() == 26)
        cout << res;
    else
        cout << "Impossible";
}