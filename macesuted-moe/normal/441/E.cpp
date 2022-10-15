#include <bits/stdc++.h>
using namespace std;

#define bufferSiz  1 << 16
char B[bufferSiz], *_S = B, *_T = B;
#define getchar() (_S == _T && (_T = (_S = B) + fread(B, 1, bufferSiz, stdin), _S == _T) ? EOF : *_S++)

template <typename T>
T read(void) {
    register T f = 1, num = 0;
    char c = getchar();
    while (!isdigit(c))
    {
        if(c=='-') f=-f;
        c = getchar();
    }
    while (isdigit(c)) num = (num << 3) + (num << 1) + (c ^ 48), c = getchar();
    return f * num;
}

#define maxn 305

double f[2][maxn];

int main()
{
    int x=read<int>(),k=read<int>();
    double p1=read<int>()/100.0,p2=1-p1;
    for(register int i=0;i<=k;i++)
        for(register int j=x+i;!(j&1);j>>=1)
            f[0][i]++;
    for(register int i=0;i<k;i++)
    {
        bool thi=i&1,tha=!thi;
        memset(f[tha],0,sizeof(f[tha]));
        for(register int j=0;j<=k;j++)
        {
            if(j) f[tha][j-1]+=p2*f[thi][j];
            if((j<<1)<=k) f[tha][j<<1]+=p1*(f[thi][j]+1);
        }
    }
    printf("%.13lf\n",f[k&1][0]);
    return 0;
}