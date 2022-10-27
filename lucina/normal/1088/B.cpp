#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,k,a[maxn],b[maxn],qs[maxn];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int t=0,c=0,sum=0,u=0;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;){
            t=i;
            b[++u]=a[i];
            while(a[i]==a[t])
                i++;
    }

    for(int i=1;i<=k;i++){
        if(b[i]==0)
        printf("%d\n",0);
        else
        printf("%d\n",b[i]-b[i-1]);
    }




}