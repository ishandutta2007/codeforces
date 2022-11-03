#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int res;
int main()
{
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            int a , b;
            cin >> a >> b;
            res += a | b;
        }
    cout << res;
}