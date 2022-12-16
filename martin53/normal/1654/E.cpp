#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42,C=400;

int n,inp[nmax];

int vals[nmax];

int eval(int d)
{
    for(int i=1;i<=n;i++)
        vals[i]=inp[i]-i*d;

    sort(vals+1,vals+n+1);

    int MX=0,cnt=0;

    for(int i=1;i<=n;i++)
    {
        if(vals[i]==vals[i-1])cnt++;
        else cnt=1;

        MX=max(MX,cnt);
    }

    return MX;
}

map<int,int> seen[nmax];

int main()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int output=n;

    for(int i=-C;i<=C;i++)
        output=min(output,n-eval(i));

    for(int j=1;j<=n;j++)
    {
        for(int i=max(1,j-nmax/C-1);i<j;i++)
            if((inp[j]-inp[i])%(j-i)==0&&abs(inp[j]-inp[i])/(j-i)>C)
            {
                int d=(inp[j]-inp[i])/(j-i);

                int cur=seen[j][d];
                if(seen[i].count(d))cur=max(cur,seen[i][d]+1);
                else cur=max(cur,2);

                seen[j][d]=cur;

                output=min(output,n-cur);
            }
    }

    printf("%i\n",output);

    return 0;
}