#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
bool visited[maxn];
int res , table;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < 2 * n; i++)
    {
        int x;
        cin >> x;
        if(visited[x])
            table--;
        else
            table++ , visited[x] = 1;
        res = max(res , table);
    }
    cout << res;
}