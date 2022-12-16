#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;
int n,inp[nmax];

int solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int outp=1e9;

    for(int cnt_1=0;cnt_1<=2;cnt_1++)
        for(int cnt_2=0;cnt_2<=2;cnt_2++)
        {
            bool can[9];
            memset(can,0,sizeof(can));
            for(int p=0;p<=cnt_1;p++)
                for(int q=0;q<=cnt_2;q++)
                    can[p+q*2]=1;

            int MX_remain=0;

            bool broken=0;

            for(int i=1;i<=n&&broken==0;i++)
            {
                int cur=inp[i];

                broken=1;

                for(int j=8;j>=0;j--)
                    if(j%3==cur%3&&j<=cur&&can[j])
                    {
                        broken=0;
                        MX_remain=max(MX_remain,(cur-j)/3);
                        break;
                    }
            }

            //cout<<cnt_1<<" "<<cnt_2<<" -> "<<MX_remain<<endl;

            if(broken==0)outp=min(outp,cnt_1+cnt_2+MX_remain);
        }
    return outp;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%i\n",solve());
    }

    return 0;
}