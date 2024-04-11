#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int a[maxn],b[maxn],n,m,m1,m2;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        m1=max(m1,a[i]);
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
        m2=max(m2,b[i]);
    }
    printf("%d %d\n",m1,m2);
}
/*
    Good Luck
        -Lucina
*/