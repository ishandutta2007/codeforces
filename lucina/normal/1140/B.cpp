#include<bits/stdc++.h>
using namespace std;
int t,n;
char s[105];

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",s+1);
        int l=0,r=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='>'&&l==0){
                l=i;
            }
            if(s[i]=='<')
                r=i;
        }
        printf("%d\n",max(0,min(l-1,n-r)));
    }
}