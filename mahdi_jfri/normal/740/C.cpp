#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int a , b , c[maxn];
ll res = 9e18;
int main()
{
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        res = min(res ,(ll) b - a + 1);
    }
    cout << res << endl;
    for(int i = 0; i < res; i++)
        c[i] = i;
    for(int i = 0; i < n; i++)
        cout << c[i % res] << " ";
}