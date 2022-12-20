#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n,inp[nmax];

vector<int> seen[nmax];

int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)seen[inp[i]].push_back(i);

    for(int i=0;i<=n;i++)seen[i].push_back(n+1);

    int outp=n;

    int prv[2]={0,0};

    for(int i=1;i<=n;i++)
    {
        if(prv[0]==prv[1]&&inp[i]==prv[0])outp--;

        if(prv[0]==inp[i])prv[1]=inp[i];
        else if(prv[1]==inp[i])prv[0]=inp[i];
        else
        {
            int p[2];

            for(int j=0;j<2;j++)
                p[j]=*lower_bound(seen[prv[j]].begin(),seen[prv[j]].end(),i);

            if(p[0]<p[1])prv[0]=inp[i];
            else prv[1]=inp[i];
        }
    }



    printf("%i\n",outp);

    return 0;
}