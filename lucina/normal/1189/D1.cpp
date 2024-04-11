#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,u,v,deg[maxn];

int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        deg[u]++;deg[v]++;
    }
    for(int i=1;i<=n;i++){
        if(deg[i]==2)return !printf("NO");
    }
    printf("YES");
}
/*
    Good Luck
        -Lucina
*/