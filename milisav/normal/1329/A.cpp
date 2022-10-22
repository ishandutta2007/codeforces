#include<bits/stdc++.h>
#define maxn 200000
using namespace std;
int n,m;
int l[maxn];
int p[maxn];
int mv[maxn];
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++) {
        scanf("%d",&l[i]);
    }
    mv[m-1]=n-l[m-1]+1;
    for(int i=m-2;i>=0;i--) {
        mv[i]=min(mv[i+1]-1,n-l[i]+1);
    }
    long long tot=0;
    for(int i=0;i<m;i++) {
        tot+=l[i];
        if(i+l[i]>n) {
            printf("-1");
            return 0;
        }
    }
    if(tot<n) {
        printf("-1");
        return 0;
    }
    int st=0;
    for(int i=0;i<m;i++) {
        if(min(st+1,mv[i])<=i) {
            printf("-1");
            return 0;
        }
        p[i]=min(st+1,mv[i]);
        st=max(st,p[i]+l[i]-1);
    }
    for(int i=0;i<m;i++) printf("%d ",p[i]);
    return 0;
}