#include<bits/stdc++.h>
using namespace std;
int a[200],n,b[200];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i+=2){
        b[i/2+i%2]=a[i];
    }
    for(int i=2;i<=n;i+=2){
        b[n-i/2+1]=a[i];
    }
    for(int i=1;i<=n;i++)
        printf("%d ",b[i]);

}