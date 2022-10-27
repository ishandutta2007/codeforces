#include<bits/stdc++.h>
using namespace std;
int n,k,a[2000],c[2000];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),c[a[i]]++;
    int sum=0,ma=0;
    for(int i=1;i<=100;i++){
        ma=max(ma,c[i]);
        if(c[i])
            sum++;
    }
    if(ma%k){
        ma=k*(ma/k+1);
    }
    printf("%d\n",ma*sum-n);
}