#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int a[maxn],n,ans;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(a[1]!=a[n])
        return printf("%d",n-1),0;
    for(int i=2;i<n;i++)
    if(a[i]!=a[1])ans=max(ans,max(i-1,n-i));
    printf("%d\n",ans);

}
/*
    Lucina
*/