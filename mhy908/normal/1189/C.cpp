#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, q;
int arr[100][100010], candy[100][100010], siz[100];
int can(int a, int b)
{
    int en=log2(b-a+1)+1;
    return candy[en][a];
}
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &arr[1][i]);
    }
    int en=0, temp=1;
    while(1){
        if(n<temp)break;
        en++;
        temp*=2;
    }
    siz[1]=n;
    for(int i=2; i<=en; i++){
        int x=0;
        for(int j=1; ; j++){
            if(siz[i-1]<j+(1<<(i-2)))break;
            ++x;
            arr[i][x]=arr[i-1][j]+arr[i-1][j+(1<<(i-2))];
            candy[i][x]=candy[i-1][j]+candy[i-1][j+(1<<(i-2))];
            if(arr[i][x]>=10)candy[i][x]++;
            arr[i][x]%=10;
        }
        siz[i]=x;
    }
    scanf("%d", &q);
    for(int u=1; u<=q; u++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", can(a, b));
    }
}