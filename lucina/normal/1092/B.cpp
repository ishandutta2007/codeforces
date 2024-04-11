#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,a[maxn],ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int k=2;k<=n;k+=2){
        ans+=(a[k]-a[k-1]);
    }
    printf("%d\n",ans);
}