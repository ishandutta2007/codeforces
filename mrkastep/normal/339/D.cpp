#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
using namespace std;

#define For(i,n) for(i=0;i<(n);i++)

int a[150000],tr[600000],depth;

int build(int l,int r,int t,int x){
    if(l==r){
        tr[x]=a[r];
        return a[r];
    }
    int m=(l+r)/2;
    if(t==0){
        return tr[x]=(build(l,m,1-t,2*x)|build(m+1,r,1-t,2*x+1));
    }
    else{
        return tr[x]=(build(l,m,1-t,2*x)^build(m+1,r,1-t,2*x+1));
    }
}

void mod(int l,int r,int p,int v){
    if(l==r){
        tr[v]=a[p];
        return;
    }
    int m=(l+r)/2;
    if(p<=m){
        depth--;
        mod(l,m,p,2*v);
        depth++;
        if(depth%2==0){
            tr[v]=tr[2*v]|tr[2*v+1];
        }
        else{
            tr[v]=tr[2*v]^tr[2*v+1];
        }
    }
    else{
        depth--;
        mod(m+1,r,p,2*v+1);
        depth++;
        if(depth%2==0){
            tr[v]=tr[2*v]|tr[2*v+1];
        }
        else{
            tr[v]=tr[2*v]^tr[2*v+1];
        }
    }
}

void solve(int n){
    int i,n1=1,m,p,b;
    n1=n1<<n;
    scanf("%d",&m);
    For(i,n1){
        scanf("%d",&a[i+1]);
    }
    build(1,n1,(n%2)^1,1);
    For(i,m){
        depth=n-1;
        scanf("%d%d",&p,&b);
        a[p]=b;
        mod(1,n1,p,1);
        printf("%d\n",tr[1]);
    }
}

int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef     ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k,l;
    while(scanf("%d",&n)!=EOF){
        solve(n);
    }
    return 0;
}