#include<bits/stdc++.h>
using namespace std;

const int nmax=1e2+42;

int inp[nmax][nmax];

int n;

int go(int b,int i,int j)
{
    cout<<b<<" "<<i<<" "<<j<<endl;

    cout.flush();

    inp[i][j]=b;
}

void greedy_fill(int blocked)
{
    for(int c=1;c<=3;c++)
        if(c!=blocked)
        {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    if(inp[i][j]==0)
                    {
                        if(inp[i-1][j]!=c&&inp[i+1][j]!=c&&inp[i][j-1]!=c&&inp[i][j+1]!=c)
                        {
                            go(c,i,j);
                            return;
                        }
                    }
        }
}
void go()
{
        int blocked;

        cin>>blocked;

        if(inp[1][1]==0)
        {
            if(blocked==1)go(2,1,1);
            else go(1,1,1);

            return;
        }

        if(inp[1][1]!=blocked)
        {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    if((i+j)%2==0)
                    {
                        if(inp[i][j]==0)
                        {
                            go(inp[1][1],i,j);
                            return;
                        }
                    }

            greedy_fill(blocked);
            return;
        }

        if(inp[1][2]==0)
        {
            if(blocked==1)go(2,1,2);
            else go(1,1,2);

            return;
        }

        if(inp[1][2]!=blocked)
        {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    if((i+j)%2)
                    {
                        if(inp[i][j]==0)
                        {
                            go(inp[1][2],i,j);
                            return;
                        }
                    }

            greedy_fill(blocked);
            return;
        }
}

int main()
{
    cin>>n;

    for(int t=1;t<=n*n;t++)
    {
        go();
    }
    return 0;
}