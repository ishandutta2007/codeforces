#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int s[maxn],n,a[maxn];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
    }
    int q,l,r;
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&l,&r);
        int x=s[r]-s[l-1];
        printf("%d\n",x/10);
    }
}
/*
    Good Luck
        -Lucina
*/