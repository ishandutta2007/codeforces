#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int b[maxn];
int x[maxn];
int a[maxn];
int n;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++) {
        a[i]=b[i]+x[i];
        x[i+1]=max(x[i],a[i]);
    }
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    return 0;
}