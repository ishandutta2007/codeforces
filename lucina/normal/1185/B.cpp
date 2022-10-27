#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,m,pt,p;
char a[maxn],b[maxn];
bool ch;

int main(){
    scanf("%d",&T);
    while(T--){
            pt=1;
        scanf("%s%s",a+1,b+1);
        ch=true;
        n=strlen(a+1);m=strlen(b+1);
        for(int i=1;i<=n;i++){
            int j=i;
            while(j<=n&&a[i]==a[j])j++;
            j--;
            p=pt;
            while(p<=m&&b[p]==b[pt])p++;
            p--;
            if(a[i]==b[pt]&&(p-pt)>=(j-i)){
                pt=p;
                pt++;
                i=j;
                continue;
            }
            else{
                ch=false;
                break;
            }
        }
        ch&=(pt==m+1);
        printf(ch?"YES\n":"NO\n");
    }
}
/*
    Good Luck
         -Lucina
*/