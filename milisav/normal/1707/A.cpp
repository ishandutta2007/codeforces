#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
int t;
int n;
int a[maxn];
int q;
char s[maxn];
bool tst(int f) {
    for(int i=0;i<n;i++) {
        if(a[i]<=q) {
            s[i]='1';
            f--;
        }
        else s[i]='0';
    }
    for(int i=n-1;i>=0;i--) {
        if(s[i]=='0' && f>0) {
            f--;
            s[i]='1';
        }
    }
    int cq=q;
    for(int i=0;i<n;i++) {
        if(s[i]=='1' && a[i]>cq) {
            cq--;
        }
    }
    return cq>=0;
}
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&q);
        s[n]=0;
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
        }
        int l=0;
        int r=n;
        while(l<r) {
            int m=(l+r+1)/2;
            if(tst(m)) l=m;
            else r=m-1;
        }
        tst(l);
        printf("%s\n",s);
    }
    return 0;
}