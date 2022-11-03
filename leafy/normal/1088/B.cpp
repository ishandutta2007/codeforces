#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100005];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int num=0;int t=k;
    for(int i=1;i<=n;i++){
        if(a[i]>num&&t>0){
            printf("%d\n",a[i]-num);
            num=a[i];t--;
        }
    }
    while(t--) printf("%d\n",0);
    return 0;
}