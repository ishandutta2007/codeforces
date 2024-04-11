#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,x,y;
int a[maxn];

int main(){
    scanf("%d%d%d",&n,&x,&y);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
            bool ch=true;
        for(int j=max(1,i-x);j<i;j++){
            ch&=(a[j]>a[i]);
        }
        for(int j=i+1;j<=min(n,i+y);j++){
            ch&=(a[j]>a[i]);
        }
        if(ch){
            printf("%d\n",i);
            return 0;
        }
    }
}
/*
    Good Luck
        -Lysithea
*/