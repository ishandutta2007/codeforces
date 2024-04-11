#include<bits/stdc++.h>
using namespace std;

const int kmax=19;

int seen[kmax][(1<<kmax)+42];

int n,k;

int noted[kmax][(1<<kmax)+42];

int main()
{
    scanf("%i%i",&n,&k);

    for(int b=0;b<k;b++)
        for(int i=0;i<(1<<k);i++)
            noted[b][i]=1<<k;

    for(int i=1;i<=n;i++)
    {
        int val;
        scanf("%i",&val);

        for(int j=0;j<k;j++)
        {
            seen[j][val]++;

            val=val/2;
        }
    }

        for(int diff=0;diff<k;diff++)
        {
            for(int a_high=0;a_high<(1<<(k-1-diff));a_high++)
                for(int x=0;x<(1<<(diff+1));x++)
            {
                int low=a_high;
                int high=a_high;

                if((x&(1<<diff)))low=low*2+1,high=high*2;
                else low=low*2,high=high*2+1;

                if(seen[diff][low]==0||seen[diff][high]==0)continue;

                for(int j=diff-1;j>=0;j--)
                {
                    int has=0;
                    if((x&(1<<j)))has=1;

                    //low^x-> 1, high^x-> 0
                    if(seen[j][low*2+(!has)]&&seen[j][high*2+has])low=low*2+(!has),high=high*2+has;
                    //same
                    else if(seen[j][low*2+has]&&seen[j][high*2+has])low=low*2+has,high=high*2+has;
                    else if(seen[j][low*2+(!has)]&&seen[j][high*2+(!has)])low=low*2+(!has),high=high*2+(!has);
                    //0 1
                    else low=low*2+has,high=high*2+(!has);
                }

                noted[diff][x]=min(noted[diff][x],(high^x)-(low^x));
                //outp=min(outp,(high^x)-(low^x));
            }
        }

    for(int x=0;x<(1<<k);x++)
    {
        int outp=1<<k;

        for(int j=k-1;j>=0;j--)
        {
            int mod=(1<<(j+1))-1;

            int remain=x&mod;

            outp=min(outp,noted[j][remain]);
        }

        printf("%i ",outp);
    }

    printf("\n");

    return 0;
}