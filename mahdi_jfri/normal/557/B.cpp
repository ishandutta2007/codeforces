#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
int a[maxn];
double ans;
int _max = -2e9 , _min = 2e9;
int main()
{
    int n , w;
    cin >> n >> w;
    for(int i = 0; i < 2 * n; i++)
        scanf("%d" , &a[i]);
    sort(a , a + 2 * n);
    int k = min(a[0] * 2, a[n]);
    ans = 1.5 * k * n;
    if(ans > w)
        ans = w;
    printf("%.6f", ans);
}