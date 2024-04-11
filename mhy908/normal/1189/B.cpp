#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
int arr[100010], x;
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr+1, arr+n+1);
    for(int i=1; i<=n-2; i++){
        if(arr[i]>arr[n]-arr[n-1]){
            x=i;
            break;
        }
    }
    if(x==0){
        printf("NO");
        return 0;
    }
    printf("YES\n");
    for(int i=x; i>=1; i--){
        printf("%d ", arr[i]);
    }
    for(int i=x+1; i<=n; i++){
        printf("%d ", arr[i]);
    }
}