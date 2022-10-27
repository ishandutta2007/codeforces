#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
char a[maxn],b[maxn];


int main(){
    int T,m,n;
    scanf("%d",&T);
    while(T--){
        scanf("%s%s",a,b);
        n=strlen(a);
        m=strlen(b);
        reverse(a,a+n);
        reverse(b,b+m);
        int k=0;
        int p1,p2;
        for(int i=0;i<n;i++){
            if(a[i]=='1'){
                p1=i;
                break;
            }
        }
        for(int i=0;i<m;i++){
            if(b[i]=='1'){
                p2=i;
                break;
            }
        }
        if(p2<=p1){
            printf("%d\n",p1-p2);
            continue;
        }
        for(int i=p2,d=0;i<n;i++,d++){
            if(a[i]=='1'){
                printf("%d\n",d);
                break;
            }
        }
    }

}
/*
    Good Luck
        -Lucina
*/