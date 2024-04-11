#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int n;
int a[maxn];
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int mn=1,mx=1;
        for(int i=2;i<=n;i++) {
            if(a[i]>a[mx]) mx=i;
            if(a[i]<a[mn]) mn=i;
        }
        printf("%d %d\n",mn,mx);
    }
    return 0;
}