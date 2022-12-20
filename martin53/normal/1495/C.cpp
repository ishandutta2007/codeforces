#include<bits/stdc++.h>
using namespace std;

const int nmax=5e2+42;

int n,m;

char inp[nmax][nmax];

int x_[4]={0,0,1,-1};
int y_[4]={1,-1,0,0};

void print()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)printf("%c",inp[i][j]);
        printf("\n");
    }

    //cout<<"---"<<endl;

}

void solve()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            char c=getchar();

            while(c!='.'&&c!='X')c=getchar();

            if(n==1||m==1)c='X';

            inp[i][j]=c;
        }

    for(int j=2;j<=m;j=j+3)
    {
        for(int i=1;i<=n;i++)
            inp[i][j]='X';
    }

    for(int j=5;j<=m;j=j+3)
    {
        int where=1;

        for(int i=1;i<=n;i++)
            if(inp[i][j-2]=='X'||inp[i][j-1]=='X')
            {
                where=i;
                break;
            }

        inp[where][j-2]='X';
        inp[where][j-1]='X';
    }

    if(m%3==1)
    {
        for(int i=1;i<=n;i++)
            if(inp[i][m]=='X')inp[i][m-1]='X';
    }

    print();
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