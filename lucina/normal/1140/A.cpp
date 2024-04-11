#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn],ct;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int ma=0;
    for(int i=1;i<=n;i++){
        ma=max(ma,a[i]);
        if(i==ma)
            ct++;
    }
    printf("%d\n",ct);
}