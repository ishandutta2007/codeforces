#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, t;
int arr[100010];

int main()
{
    scanf("%d", &t);
    for(int u=1; u<=t; u++){
        scanf("%d", &n);
        for(int i=1; i<=n; i++){
            scanf("%d", &arr[i]);
        }
        sort(arr+1, arr+n+1);
        printf("%d\n", min(arr[n-1]-1, n-2));
    }
}