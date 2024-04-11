#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,q,a[410];

int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        int pos;
        for(int i=1;i<=n;i++){
           scanf("%d",&a[i]);
            a[i+n]=a[i];
            if(a[i]==1)
                pos=i;
        }
        bool cw=true;
        for(int j=2;j<=n;j++){
            cw&=(a[pos+j-1]==j);
        }
        if(cw){
            printf("YES\n");
            continue;
        }
        for(int i=1;i<=n;i++){
            if(a[i]==n)
                pos=i;
        }
        cw=true;
        for(int j=1;j<n;j++){
            cw&=(a[pos+j]==n-j);
        }
        printf(cw?"YES\n":"NO\n");
    }
}