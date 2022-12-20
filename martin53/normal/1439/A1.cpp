#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42,MX=1e6+42;

int n,m;

char inp[nmax][nmax];

int pointer=0;
int x1[MX],y1[MX],x2[MX],y2[MX],x3[MX],y3[MX];

bool dumb(int a,int b,int c,int d)
{
    int diff=abs(a-c)+abs(b-d);

    return 1<=diff&&diff<=2;
}
void add(int a,int b,int c,int d,int e,int f)
{
    assert(dumb(a,b,c,d));
    assert(dumb(c,d,e,f));
    assert(dumb(e,f,a,b));

    pointer++;

    inp[a][b]='1'-inp[a][b]+'0';
    inp[c][d]='1'-inp[c][d]+'0';
    inp[e][f]='1'-inp[e][f]+'0';

    x1[pointer]=a;
    y1[pointer]=b;

    x2[pointer]=c;
    y2[pointer]=d;

    x3[pointer]=e;
    y3[pointer]=f;
}

int x_[4]={0,0,1,1};
int y_[4]={0,1,0,1};

void go(int i,int j,int cnt)
{
    if(cnt==0)return;

    if(cnt==1)
    {
        if(inp[i][j]=='1')
        {
            add(i,j,i+1,j,i,j+1);
        }
        else
        {
            add(i+1,j,i,j+1,i+1,j+1);
        }

        go(i,j,2);
        return;
    }

    if(cnt==3)
    {
        vector< pair<int,int> > v={};

        for(int t=0;t<4;t++)
            if(inp[i+x_[t]][j+y_[t]]=='1')v.push_back({i+x_[t],j+y_[t]});

        add(v[0].first,v[0].second,v[1].first,v[1].second,v[2].first,v[2].second);
        return;
    }

    if(cnt==4)
    {
        add(i,j,i+1,j,i,j+1);
        go(i,j,1);
        return;
    }

    int x_other=i,y_other=j;

    if(inp[i][j]=='0')
    {
        if(inp[i+1][j]=='1')x_other=i+1;
        else y_other=j+1;
    }

    vector< pair<int,int> > v={};

    for(int t=0;t<4;t++)
        if(i+x_[t]!=x_other||j+y_[t]!=y_other)v.push_back({i+x_[t],j+y_[t]});

    add(v[0].first,v[0].second,v[1].first,v[1].second,v[2].first,v[2].second);

    go(i,j,3);
}

mt19937 rng(42);

void solve()
{
    pointer=0;
    /*
    n=rng()%2+2;
    m=rng()%2+2;
    */
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)cin>>inp[i][j];
            //inp[i][j]=rng()%2+'0';


    if(n%2==1)
    {
        for(int j=1;j<=m;j++)
        {
            if(inp[n][j]=='1')
            {
                if(j==1)add(n,1,n-1,1,n-1,2);
                else add(n,j,n-1,j,n-1,j-1);
            }
        }
    }

    if(m%2==1)
    {
        for(int i=1;i<=n-n%2;i++)
        {
            if(inp[i][m]=='1')
            {
                if(i==1)add(1,m,1,m-1,2,m-1);
                else add(i,m,i,m-1,i-1,m-1);
            }
        }
    }

    for(int i=1;i<=n/2*2;i=i+2)
        for(int j=1;j<=m/2*2;j=j+2)
        {
            int cnt=(inp[i][j]=='1')+(inp[i+1][j]=='1')+(inp[i][j+1]=='1')+(inp[i+1][j+1]=='1');

            //cout<<"cnt= "<<cnt<<i<<" "<<j<<endl;

            go(i,j,cnt);
        }

    assert(pointer<=n*m);

    cout<<pointer<<endl;
    for(int i=1;i<=pointer;i++)
    {
        cout<<x1[i]<<" "<<y1[i]<<" "<<x2[i]<<" "<<y2[i]<<" "<<x3[i]<<" "<<y3[i]<<endl;
    }

    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)cout<<inp[i][j]<<" ";cout<<endl;
    }
    */

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            assert(inp[i][j]=='0');
}

int main()
{
    int t;

    //freopen("output.c","w",stdout);

    //t=1e5;

    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }
    return 0;
}