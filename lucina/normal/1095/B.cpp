#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int ans=1e9;
    if(n>2){
    ans=a[n]-a[1];
    ans=min(ans,a[n]-a[2]);
    ans=min(ans,a[n-1]-a[1]);
    printf("%d\n",ans);
    }
    else{
        printf("%d\n",0);
    }


}