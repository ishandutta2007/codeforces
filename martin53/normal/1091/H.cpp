#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

bool valid[nmax];

int n,f;

vector<int> seen[nmax];

int g[nmax];

int main()
{
    scanf("%i%i",&n,&f);

    for(int i=2;i<nmax;i++)
    if(i!=f)
    {
        int cnt=0,mem_i=i;

        for(int j=2;j*j<=mem_i;j++)
            while(mem_i%j==0)
            {
                mem_i=mem_i/j;
                cnt++;
            }
        if(mem_i!=1)cnt++;

        if(cnt<3)
        {
            valid[i]=1;
            //cout<<i<<endl;
        }
    }

    for(int i=0;i<nmax;i++)
    {
        g[i]=0;

        for(int j=0;true;j++)
        {
            g[i]=j;

            bool found=0;

            for(auto k:seen[j])
            {
                //cout<<i<<" "<<k<<endl;

                if(valid[i-k])
                {
                    found=1;
                    break;
                }
            }

            if(found==0)
            {
                break;
            }
        }

        seen[g[i]].push_back(i);

        //cout<<i<<" -> "<<g[i]<<endl;
    }

    int val=0;

    for(int i=1;i<=n;i++)
    {
        int b,w,r;

        scanf("%i%i%i",&b,&w,&r);

        val=val^g[w-b-1];
        val=val^g[r-w-1];
    }

    if(val)printf("Alice\nBob\n");
    else printf("Bob\nAlice\n");
    return 0;
}