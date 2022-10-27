#include<bits/stdc++.h>
using namespace std;
int n,c[3],x;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        c[x]++;
    }
    if(c[2]>0)printf("2 "),c[2]--,n--;
    else printf("1 "),c[1]--,n--;
    if(c[1]>0)printf("1 "),c[1]--,n--;
    for(int i=1;i<=n;i++){
        if(c[2])printf("2 "),c[2]--;
        else printf("1 "),c[1]--;
    }
}