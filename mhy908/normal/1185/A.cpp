#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int n;
LL arr[5], d, ans;

int main()
{
    scanf("%lld %lld %lld %lld", &arr[1], &arr[2], &arr[3], &d);
    sort(arr+1, arr+4);
    if(arr[2]-arr[1]<d)ans+=d-arr[2]+arr[1];
    if(arr[3]-arr[2]<d)ans+=d-arr[3]+arr[2];
    printf("%lld", ans);
}