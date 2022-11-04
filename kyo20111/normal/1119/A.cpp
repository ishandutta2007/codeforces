#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,arr[303030],ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);

    for(int i=1;i<n;i++) if(arr[i] != arr[n]){
        ans=n-i;
        break;
    }

    for(int i=n;i>=2;i--) if(arr[i] != arr[1]){
        ans=max(ans,i-1);
        break;
    }

    printf("%d",ans);
}