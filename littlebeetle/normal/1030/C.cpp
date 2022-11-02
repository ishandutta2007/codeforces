#include<cstdio>
const int N=100002;
int n,k,i,g,p;
char s[N];//
int main(){
    scanf("%d%s",&n,s+1);
    for(k=0;k<=n*9;k++){
        g=0;
        for(i=1;i<=n;i++){
            g+=s[i]-48;
            if(g==k)
                g=0;
        }
        if(g==0){
            p++;
        }
        if(p==2){
            printf("YES");
            return 0;
        }
    }
    printf("NO");
}