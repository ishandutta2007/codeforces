#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
long long a[maxn],b[maxn],n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n/2;i++)
        scanf("%lld",&b[i]);
    a[n/2]=b[n/2]/2;
    a[n/2+1]=b[n/2]-a[n/2];
    for(int i=1;i<=n/2-1;i++){
        if(b[n/2-i]>=b[n/2-i+1]){
            a[n/2-i]=a[n/2-i+1];
            a[n/2+i+1]=b[n/2-i]-a[n/2-i];
        }
        else{
            a[n/2+i+1]=a[n/2+i];
            a[n/2-i]=b[n/2-i]-a[n/2+i+1];
        }
    }
    for(int i=1;i<=n;i++)
        printf("%lld ",a[i]);
    }