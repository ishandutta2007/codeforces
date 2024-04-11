#include <bits/stdc++.h>

#define S second
#define F first

using namespace std;
typedef long long ll;

vector<int> ans;

    int a = 0, b = 0, c = 0;
    int m[1000], m1[1000];
    int n, s;

int dp[105][1005];
int vis[105][1005];

void f(int cur, int s1)
{
    if (vis[cur][s1]) return;
    if (cur == n)
    {
        if (s1 == s)
        {
            cout << "YES";
            exit(0);
        }
    }
    f(cur + 1, s1);
    f(cur + 1, s1 + m[cur]);
    vis[cur][s1] = true;
}

int main()
{
    int sum = 0;
    cin >> n >> s;
    for(int i = 0; i < n; i++)
    {
        cin>>m[i];
        sum += m[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (sum - m[i] <= s) {cout<<"YES"; return 0;}
    }
    cout << "NO";
}