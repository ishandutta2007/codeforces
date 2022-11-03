#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
int a[maxn];
int main()
{
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a , a + n);
    for(int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        int k = upper_bound(a , a + n, b) - a;
        if(a[k - 1] > b)
            k--;
        if(k < 0)
            k = 0;
        cout << k << " ";
    }
}