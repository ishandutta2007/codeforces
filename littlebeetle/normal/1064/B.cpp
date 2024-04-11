#include<cstdio>
int t,a,s;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&a);
        s=1;
        while(a){
            if(a&1)
            s<<=1;
            a>>=1;
        }
        printf("%d\n",s);
    }
}