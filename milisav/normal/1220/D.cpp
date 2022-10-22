#include<bits/stdc++.h>
using namespace std;
int n;
long long b[300000];
int ct[70];
int val[300000];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%lld",&b[i]);
        long long t=0;
        while(b[i]%(1ll<<(t+1ll))==0) t++;
        val[i]=t;
        ct[t]++;
    }
    int mv=0;
    for(int i=0;i<70;i++) if(ct[i]>ct[mv]) mv=i;
    printf("%d\n",n-ct[mv]);
    for(int i=0;i<n;i++) {
        if(val[i]!=mv) printf("%lld ",b[i]);
    }
    return 0;
}