#include <stdio.h>
#include <map>
using namespace std;
typedef unsigned __int64 ui64;

ui64 L,R,D=2520;
ui64 TP[20],TPD[20];
map<ui64, map<ui64, ui64> > CHK[20];

ui64 gcd(ui64 a, ui64 b){return ((b==0)?a:gcd(b,a%b));}
ui64 CNT(ui64 V, ui64 G, ui64 R, ui64 U, int l)
{
    if (V < U) return 0;
    if (l < 0) return (R % G) == 0;

    int i; ui64 D,RES = 0;
    if (V / TP[l+1] == U / TP[l+1]){
        for (i=0;i<=9;i++){
            if (i == 0) D = G;
            else D = G / gcd(G,i) * i;
            RES += CNT(V,D,(R+TPD[l]*i)%2520,U+TP[l]*i,l-1);
        }
        return RES;
    }
    else{
        if (CHK[l][G][R]) return CHK[l][G][R];
        for (i=0;i<=9;i++){
            if (i == 0) D = G;
            else D = G / gcd(G,i) * i;
            CHK[l][G][R] += CNT(V,D,(R+TPD[l]*i)%2520,U+TP[l]*i,l-1);
        }
        return CHK[l][G][R];
    }
}

int main()
{
    int i;

    TP[0] = TPD[0] = 1;
    for (i=1;i<20;i++){
        TP[i] = TP[i-1] * 10;
        TPD[i] = TP[i] % D;
    }

    scanf ("%d",&i); while (i--){
        scanf ("%I64u %I64u",&L,&R);
        printf ("%I64u\n",CNT(R,1,0,0,18)-CNT(L-1,1,0,0,18));
    }

    return 0;
}