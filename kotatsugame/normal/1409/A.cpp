#include<cstdio>
using namespace std;
int T,A,B;
main(){
    scanf("%d",&T);
    for(;T--;)
    {
        scanf("%d%d",&A,&B);
        A-=B;
        if(A<0)A=-A;
        printf("%d\n",(A+9)/10);
    }
}