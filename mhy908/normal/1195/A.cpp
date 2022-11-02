#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, k, arr[1010];
int ans, num;
int main()
{
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++){
        int a;
        scanf("%d", &a);
        arr[a]++;
    }
    num=(n+1)/2;
    for(int i=1; i<=k; i++){
        if(arr[i]>=2){
            if(num*2>=arr[i]-arr[i]%2){
                num-=arr[i]/2;
                ans+=arr[i]-arr[i]%2;
                arr[i]%=2;
            }
            else{
                ans+=num*2;
                arr[i]-=num*2;
                num=0;
            }
        }
    }
    if(num==0){
        printf("%d", ans);
        return 0;
    }
    for(int i=1; i<=k; i++){
        if(arr[i]&&num>0){
            num--;
            ans++;
        }
    }
    printf("%d", ans);
}