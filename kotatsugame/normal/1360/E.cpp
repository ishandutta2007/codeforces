#include<cstdio>
using namespace std;
int T,N;
char S[55][55];
main()
{
    scanf("%d",&T);
    for(;T--;)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)scanf("%s",S[i]);
        bool out=false;
        for(int i=0;i<N-1;i++)for(int j=0;j<N-1;j++)if(S[i][j]=='1')
        {
            if(S[i+1][j]=='0'&&S[i][j+1]=='0')out=true;
        }
        puts(out?"NO":"YES");
    }
}