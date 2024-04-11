#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
int arr[110], one[110];
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%1d", &arr[i]);
        one[i]=one[i-1]+(arr[i]==1);
    }
    if(n%2||(one[n]!=n/2&&n%2==0)){
        printf("1\n");
        for(int i=1; i<=n; i++){
            printf("%d", arr[i]);
        }
    }
    else{
        printf("2\n");
        for(int i=1; i<n; i++){
            printf("%d", arr[i]);
        }
        printf(" %d", arr[n]);
    }
}