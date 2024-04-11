#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int maxn = 1e2 + 20;
int a[maxn] , sum , res;
int main()
{
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
    {
        if(sum + a[i] <= m)
            sum += a[i];
        else
            sum = a[i] , res++;
    }
    if(sum)
        res++;
    cout << res;
}