#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (a & (1 << b))
const int maxn = 1e5 + 20;
int a[maxn] , _max = -1, res;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i] , _max = max(_max , a[i]);
    for(int i = 0; i < n; i++)
        res += _max - a[i];
    cout << res;
}