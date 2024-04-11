#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
int arr[200010];
int st, fin;
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
        if(arr[i]==n)st=fin=i;
    }
    for(int i=n-1; i>=1; i--){
        if(arr[st-1]==i)st--;
        else if(arr[fin+1]==i)fin++;
        else{
            printf("NO");
            return 0;
        }
    }
    printf("YES");
}