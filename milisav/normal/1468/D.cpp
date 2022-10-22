#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;
int t;
int n,m,a,b;
int s[maxn];
int tl[maxn];
bool pos(int c) {
    for(int i=0;i<c;i++) {
        if(s[c-i-1]>tl[i]) {
            return false;
        }
    }
    return true;
}
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d %d %d",&n,&m,&a,&b);
        if(b<a) {
            a=n-a+1;
            b=n-b+1;
        }
        for(int i=0;i<m;i++) {
            scanf("%d",&s[i]);
        }
        sort(s,s+m);
        int r=min(m,b-a-1);
        for(int i=0;i<r;i++) {
            tl[i]=b-i-2;
        }
        int l=0;
        while(l<r) {
            int s=(l+r+1)/2;
            if(pos(s)) l=s;
            else r=s-1;
        }
        printf("%d\n",l);
    }
    return 0;
}