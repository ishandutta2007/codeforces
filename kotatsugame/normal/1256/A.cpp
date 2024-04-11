#include<cstdio>
using namespace std;
int T,A,B,N,S;
main()
{
    scanf("%d",&T);
    for(;T--;)
    {
        scanf("%d%d%d%d",&A,&B,&N,&S);
        int T=S/N;
        if(T>A)T=A;
        S-=T*N;
        puts(S>B?"NO":"YES");
    }
}