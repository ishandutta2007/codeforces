#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int por[maxn];
int sor[maxn];
int a[maxn];
int n;
int f(int x,int y) {
    return (x|y)-y;
}
int value_i(int i) {
    return f(a[i],por[i-1]|sor[i+1]);
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        por[i]=por[i-1]|a[i];
    }
    for(int i=n;i>=1;i--) sor[i]=sor[i+1]|a[i];
    int bi=1;
    for(int i=2;i<=n;i++) {
        if(value_i(i)>value_i(bi)) bi=i;
    }
    printf("%d ",a[bi]);
    for(int i=1;i<=n;i++) {
        if(i!=bi) printf("%d ",a[i]);
    }
    return 0;
}