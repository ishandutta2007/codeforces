#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;
int n,inp[nmax];

bool been[nmax];

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)
    {
        been[i]=0;
        inp[i]=i-inp[i];
    }

    //for(int i=1;i<=n;i++)cout<<inp[i]<<" ";cout<<endl;

    for(int i=1;i<=n;i++)
        if(been[i]==0)
        {
            int j=i;

            vector<int> cycle={};

            while(been[j]==0)
            {
                cycle.push_back(j);

                been[j]=1;

                j=inp[j];
            }

            //for(auto w:cycle)cout<<w<<" ";cout<<endl;

            for(int p=0;p<cycle.size();p++)
                if(cycle[p]==j)
                {
                    printf("%i",cycle.size()-p);

                    for(int t=p;t<cycle.size();t++)
                        printf(" %i",cycle[t]);
                    printf("\n");
                    return;
                }
        }
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }
    return 0;
}