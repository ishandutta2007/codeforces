#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,arr[101010],m;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    for(int i=1;i<=n;i++) arr[i] += arr[i-1];
    scanf("%d",&m);
    while(m--){
        int a,b; scanf("%d %d",&a,&b);
        printf("%d\n",(arr[b]-arr[a-1])/10);
    }
}