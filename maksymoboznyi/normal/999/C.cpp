#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define x first
#define y second

using namespace std;
const int N = 5e5+5;
const long long inf = 2e18;

vector<int> g[100];
int num[100];
int n, k;
string s;
bool used[N];
signed main()
{
    cin >> n >> k >> s;
    for (int i = 0; i < n; i++)
        g[s[i]-'a'].pb(i);
    int kol = 0;
    for (int i = 1; i <= k; i++)
        for (int j = 'a'; j <= 'z'; j++)
            if (num[j-'a'] < g[j-'a'].size())
            {
                used[g[j-'a'][num[j-'a']]] = 1;
                num[j-'a']++;
                //cout << g[j-'a'][num[j-'a']-1] << endl;
                kol++;
                break;
            }
    for (int i = 0; i < n; i++)
        if (!used[i])
            cout << s[i];
    return 0;
}