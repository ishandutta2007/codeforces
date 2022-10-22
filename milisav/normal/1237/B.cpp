#include<bits/stdc++.h>
using namespace std;
int n;
int a[200000];
int b[200000];
int p[200000];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) {
        scanf("%d",&b[i]);
        p[b[i]]=i;
    }
    for(int i=1;i<=n;i++) b[p[a[i]]]=i;
    int mv=n+1;
    int cnt=0;
    //for(int i=1;i<=n;i++) cout<<b[i]<<" ";
    for(int i=n;i>=1;i--) {
        if(b[i]>mv) cnt++;
        mv=min(mv,b[i]);
    }
    printf("%d",cnt);
    return 0;
}