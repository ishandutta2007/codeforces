#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
const int maxn = 2e5 + 20;
int res , f1 , f2;
pair<int , int> a[maxn] , b[maxn];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
        cin >> b[i].first >> b[i].second;
    sort(a , a + n);
    sort(b , b + m);
    for(int i = 0; i < n; i++)
        res = max(res , -a[i].second + b[m - 1].first);
    for(int i = 0; i < m; i++)
        res = max(res , -b[i].second + a[n - 1].first);
    cout << res << endl;
}