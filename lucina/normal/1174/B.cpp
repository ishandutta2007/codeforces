#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn],pa;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    bool same=true;
    for(int i=1;i<=n;i++){
        same&=((a[i]-a[1])%2==0);
    }
    if(same){
        for(int i=1;i<=n;i++)
            printf("%d ",a[i]);
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);

}