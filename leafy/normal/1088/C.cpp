#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),a[i]+=500000;
    int num=n+1;
    printf("%d\n",num);
    printf("1 %d %d\n",n,500000);
    num=1;
    for(int i=1;i<=n;i++){
        printf("2 %d %d\n",i,a[i]-i+1);
    }
    return 0;

}