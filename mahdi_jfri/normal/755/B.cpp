#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e3 + 20;
string a[maxn] , b[maxn];
map<string , bool> mp;
int res;
int main()
{
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i] , mp[a[i]] = 1;
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
        if(mp[b[i]])
            res++;
    }
    if(res % 2)
        n++;
    m -= res;
    n -= res;
    if(m >= n)
        cout << "NO";
    else
        cout << "YES";
}