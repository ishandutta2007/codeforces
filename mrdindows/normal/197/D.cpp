#include <iostream>
using namespace std;

bool e=false;
int n,m;
bool **a;
bool **b;
int **xx;
int **yy;
void go(int x,int y)
{
    if (!e)
    {
        if (b[x%n][y%m]) 
        {
            if (x!=xx[x%n][y%m] || y!=yy[x%n][y%m]) 
            {
                    cout<<"Yes";
                    e=true;
                    return;
            }
        }
        else
        {
        b[x%n][y%m]=true;
        xx[x%n][y%m]=x;
        yy[x%n][y%m]=y;
        if (a[(x+1)%n][y%m]) go(x+1,y);
        if (a[(x-1)%n][y%m]) go(x-1,y);
        if (a[(x)%n][(y+1)%m]) go(x,y+1);
        if (a[(x)%n][(y-1)%m]) go(x,y-1);
        }
    }
}   
int main()
{ 

    int x,y;
    cin>>n>>m;
    a=new bool*[n];
    b=new bool*[n];
    xx=new int*[n];
    yy=new int*[n];
    for (int i=0;i<n;i++)
    {
        a[i]=new bool[m];
        b[i]=new bool[m];
        xx[i]=new int[m];
        yy[i]=new int[m];
        for (int j=0;j<m;j++)
        {
            b[i][j]=false;
            char c;
            cin>>c;
            if (c=='#') a[i][j]=false;
            else a[i][j]=true;
            if (c=='S') 
            {
                x=i;
                y=j;
            }
        }
    }
    x+=n*(2147000000/(2*n)-1);
    y+=m*(2147000000/(2*m)-1);
    go(x,y);
    if (!e) cout<<"No";
    return 0;
}