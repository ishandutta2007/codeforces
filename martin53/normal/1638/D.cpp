#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42;

int n,m;

int inp[nmax][nmax];

bool in_queue[nmax][nmax];

queue< pair<int,int> > q;

void test(int x,int y)
{
    if(x<1||x>=n||y<1||y>=m)return;

    if(in_queue[x][y])return;

    int colour_prv=0;

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            if(inp[i+x][j+y]!=0)
            {
                if(colour_prv==0)colour_prv=inp[i+x][j+y];
                else if(colour_prv!=inp[i+x][j+y])return;
            }

    in_queue[x][y]=1;
    q.push({x,y});
}

void init()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%i",&inp[i][j]);
}

vector< pair< pair<int,int>, int > > output;

void solve()
{
    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
            test(i,j);

    while(q.size())
    {
        pair<int,int> tp=q.front();
        q.pop();

        int colour=0;

        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
            {
                if(colour==0)colour=inp[i+tp.first][j+tp.second];
                inp[i+tp.first][j+tp.second]=0;
            }

        if(colour==0)continue;

        for(int i=-1;i<=1;i++)
            for(int j=-1;j<=1;j++)
                test(i+tp.first,j+tp.second);

        output.push_back({tp,colour});
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(inp[i][j])
            {
                printf("-1\n");
                return;
            }

    reverse(output.begin(),output.end());

    printf("%i\n",output.size());
    for(auto w:output)
        printf("%i %i %i\n",w.first.first,w.first.second,w.second);
}

int main()
{
    init();

    solve();

    return 0;
}