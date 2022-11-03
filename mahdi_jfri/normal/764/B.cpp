#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
ll a[maxn];
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n / 2; i++)
    {
        if((i) % 2)
            swap(a[i] , a[n - i + 1]);
    }
    for(int i = 1; i <= n; i++)
        cout << a[i] << " ";
}