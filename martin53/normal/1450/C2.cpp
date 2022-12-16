#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42;
int n;

char inp[nmax][nmax];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)cin>>inp[i][j];

    int total=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(inp[i][j]!='.')total++;

    for(int force_x=0;force_x<3;force_x++)
        for(int force_o=0;force_o<3;force_o++)
            if(force_o!=force_x)
            {
                int cur=0;

                for(int i=1;i<=n;i++)
                    for(int j=1;j<=n;j++)
                        if((i+j)%3==force_x&&inp[i][j]=='O')cur++;
                        else if((i+j)%3==force_o&&inp[i][j]=='X')cur++;

                if(cur<=total/3)
                {
                    //cout<<"cur= "<<cur<<endl;

                    for(int i=1;i<=n;i++)
                        for(int j=1;j<=n;j++)
                            if((i+j)%3==force_x&&inp[i][j]=='O')inp[i][j]='X';
                            else if((i+j)%3==force_o&&inp[i][j]=='X')inp[i][j]='O';

                    force_o=3;
                    force_x=3;
                }


            }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<inp[i][j];
        }
        cout<<endl;
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