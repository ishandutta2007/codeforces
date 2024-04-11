#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int t,n,a,b;
bool x;
char s[maxn];
int main(){
    scanf("%d",&t);
    for(int kk=1;kk<=t;kk++){
        scanf("%s",s);
       x=true;
       n=strlen(s);
       for(int i=0;i<n&&x;i++){
            for(int j=0;j<n&&x;j++){
                if(s[i]!=s[j]){
                    a=i;
                    b=j;
                     x=false;
                    break;
                }
            }
       }
       if(x){
        printf("-1\n");
        }
        else{
            printf("%c",s[a]);
            for(int i=0;i<n;i++){
                if(i!=a&&i!=b)
                    printf("%c",s[i]);
            }
            printf("%c\n",s[b]);
        }
       }
    }