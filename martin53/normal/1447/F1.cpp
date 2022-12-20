#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42,SZ=105;

int n,inp[nmax];

int cnt[nmax][SZ];

vector< int/*left*/ > mem[SZ][SZ];

int outp;

int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int MX=0;
    for(int i=1;i<=n;i++)
        MX=max(MX,inp[i]);

    for(int i=1;i<=MX;i++)
        for(int j=1;j<=MX;j++)
            mem[i][j].push_back(0);

    for(int r=1;r<=n;r++)
    {
        for(int val=1;val<=MX;val++)
        {
            cnt[r][val]=cnt[r-1][val];
            if(val==inp[r])cnt[r][val]++;
        }

        int best=0;
        for(int i=1;i<=MX;i++)
            if(cnt[r][i]>cnt[r][best])best=i;

        for(int other=1;other<=MX;other++)
            {
                int diff=cnt[r][inp[r]]-cnt[r][other];

                if(diff<mem[inp[r]][other].size()||diff<0)continue;

                //cout<<inp[r]<<" and "<<other<<" moment "<<r<<" size "<<mem[inp[r]][other].size()<<" diff "<<diff<<endl;

                if(diff!=mem[inp[r]][other].size())assert(0==1);

                mem[inp[r]][other].push_back(r);
            }

        for(int other=1;other<=MX;other++)
            if(other!=best)
            {
                int LHS=cnt[r][best]-cnt[r][other];

                //cout<<r<<" "<<best<<" "<<other<<" "<<LHS<<" "<<mem[best][other].size()<<endl;

                if(mem[best][other].size()>LHS)
                {
                    //cout<<"found "<<mem[best][other][LHS]<<endl;

                    outp=max(outp,r-mem[best][other][LHS]);
                }
            }
    }

    printf("%i\n",outp);
    return 0;
}