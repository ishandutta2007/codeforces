#include<bits/stdc++.h>
using namespace std;
int a[500],n,ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        if(a[i-1]==1&&a[i]==0&&a[i+1]==1){
            a[i+1]=0;
            ans++;
        }
    }
    printf("%d\n",ans);
}