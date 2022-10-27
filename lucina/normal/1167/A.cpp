#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,t,pt;
char s[maxn];

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%s",&n,s+1);
        pt=n+1;
        for(int i=1;i<=n;i++){
            if(s[i]=='8'){
                pt=i;
                break;
            }
        }
        if(n-pt+1>=11)
            printf("YES\n");
        else
            printf("NO\n");
    }

}