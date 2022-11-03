#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+20;
int n , k;
string s[4];
bool visited[2][maxn];
void dfs(int v, bool x, int water)
{
    if(v >= n)
    {
        cout << "YES";
        exit(0);
    }
    if(v < 0 || s[x][v] == 'X' || v <= water || visited[x][v]) return;
    visited[x][v] = 1;
    dfs(v + k, 1 - x, water + 1);
    dfs(v + 1, x, water + 1);
    dfs(v - 1, x, water + 1);
}
int main()
{
    cin >> n >> k >> s[0] >> s[1];
    dfs(0,0,-1);
    cout << "NO";
}