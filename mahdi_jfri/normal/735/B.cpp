#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
double ans;
ll a[maxn] , sum;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int n , n1 , n2;
    cin >> n >> n1 >> n2;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    if(n1 > n2)
        swap(n1 , n2);

    sort(a , a + n , cmp);
    for(int i = 0; i < n1; i++)
        sum += a[i];
    ans = (double)sum / (double)n1;
    sum = 0;
    for(int i = n1; i < n2 + n1; i++)
        sum += a[i];
    ans += (double)sum / (double)n2;
    printf("%.12f", ans);
}