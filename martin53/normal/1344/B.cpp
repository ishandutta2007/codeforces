#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42;

int n,m;
char inp[nmax][nmax];

void no()
{
    cout<<-1<<endl;
    exit(0);
}

queue< pair<int,int> > q;

int x_move[4]={0,0,-1,1};
int y_move[4]={1,-1,0,0};

bool proper(int x,int y)
{
    return 1<=x&&x<=n&&1<=y&&y<=m&&inp[x][y]=='#';
}

bool been[nmax][nmax];

int on_x[nmax];
int on_y[nmax];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)cin>>inp[i][j];

    for(int i=1;i<=n;i++)
    {
        int lst=0;
        for(int j=1;j<=m;j++)
            if(inp[i][j]=='#')
            {
                if(lst==0||lst==j-1)lst=j;
                else no();
            }
    }

    for(int j=1;j<=m;j++)
    {
        int lst=0;
        for(int i=1;i<=n;i++)
            if(inp[i][j]=='#')
            {
                if(lst==0||lst==i-1)lst=i;
                else no();
            }
    }

    int cnt=0;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(inp[i][j]=='#'&&been[i][j]==0)
            {
                q.push({i,j});

                while(q.size())
                {
                    pair<int,int> tp=q.front();
                    q.pop();

                    if(been[tp.first][tp.second])continue;

                    been[tp.first][tp.second]=1;

                    on_x[tp.first]=1;
                    on_y[tp.second]=1;

                    for(int t=0;t<4;t++)
                    {
                        int x_=tp.first+x_move[t];
                        int y_=tp.second+y_move[t];

                        if(proper(x_,y_))q.push({x_,y_});
                    }
                }
                cnt++;
            }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(on_x[i]==0&&on_y[j]==0)been[i][j]=1;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(been[i][j])
            {
                on_x[i]=1;
                on_y[j]=1;
            }

    for(int i=1;i<=n;i++)
        if(on_x[i]==0)no();

    for(int j=1;j<=m;j++)
        if(on_y[j]==0)no();

    printf("%i\n",cnt);
    return 0;
}