#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,k,a[maxn],t,res,j;
char s[22];

int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<=n;i++)
        a[i]=-555555;
    for(int i=0;i<=n;i++){
        scanf("%s",s);
        if(s[0]=='?'){
            t++;
            continue;
        }
        if(s[0]=='-'){
            res=0; j=1;
            while(s[j]!='\0'){
                res*=10;
                res+=(s[j]-'0');
                j++;
            }
            a[i]=-res;
        }
        else{
            res=0;j=0;
            while(s[j]!='\0'){
                res*=10;
                res+=(s[j]-'0');
                j++;
            }
            a[i]=res;
        }
        }
    if(k==0){
        if(a[0]!=-555555){
            printf(a[0]!=0?"NO":"YES");
            return 0;
        }
        printf((n-t)&1?"NO":"YES");
        return 0;
    }
    if(t>0){
        printf(n&1?"YES":"NO");
        return 0;
    }
    long long sum=a[0],g=1;
    for(int i=0;i<n;i++){
        if(a[i]%k){
            printf("NO");
            return 0;
        }
        a[i+1]+=(a[i]/k);
    }
    printf(a[n]==0?"YES":"NO");

}