#include <stdio.h>

int main()
{
    int data[14],mancala[14],i,j,n;
    long long int score,maxs=0ll;
    for(i=0;i<14;i++)
        scanf("%d",&data[i]);
    for(i=0;i<14;i++)
    {
        score=0ll;
        for(j=0;j<14;j++)
            mancala[j]=data[j];
        n=mancala[i];
        mancala[i]=0;
        for(j=1;j<=14;j++)
        {
            mancala[(i+j)%14]+=n/14;
            if(j<=n%14)
                mancala[(i+j)%14]++;
            if(mancala[(i+j)%14]%2==0)
                score+=mancala[(i+j)%14];
        }
        if(score>maxs)
            maxs=score;
    }
    printf("%lld",maxs);
}