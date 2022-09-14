#include<cstdio>
using namespace std;
int T,N;
char S[55];
main()
{
    scanf("%d",&T);
    for(;T--;)
    {
        scanf("%d%s",&N,S);
        int ans=0,now=0;
        for(int i=0;i<N;i++)
        {
            if(S[i]=='(')now++;
            else
            {
                now--;
                if(now<0)ans-=now,now=0;
            }
        }
        printf("%d\n",ans);
    }
}