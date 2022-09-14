#include<cstdio>
using namespace std;
int N;
int A[4<<17];
main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
        A[N+i]=A[i];
    }
    int ans=0;
    for(int i=0;i<N;)
    {
        if(A[i]==0)i++;
        else
        {
            int j=i;
            while(A[j]==1)j++;
            if(ans<j-i)ans=j-i;
            i=j;
        }
    }
    printf("%d\n",ans);
}