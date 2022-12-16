#include<bits/stdc++.h>
using namespace std;
const int nmax=1e2+42;
int n;

int output[nmax][nmax];

int in=0;
int ask(int x1,int y1,int x2,int y2)
{
    in++;
    if(x1>x2)swap(x1,x2);
    if(y1>y2)swap(y1,y2);
    cout<<"? "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    cout.flush();
    int ret;
    cin>>ret;
    return ret;
}
void print()
{
    cout<<"!"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<output[i][j];
        cout<<endl;
    }

}

int inp[3][3];

set<int> seen[100];

int my_test(int x1,int y1,int x2,int y2)
{
    if(inp[x1][y1]!=inp[x2][y2])return 0;

    if(x1+1==x2)
    {
        return inp[x1+1][y1]==inp[x2][y2-1]||inp[x1][y1+1]==inp[x2][y2-1]||inp[x1][y1+1]==inp[x2-1][y2];
    }
    //y1+1=y2
    return inp[x1+1][y1]==inp[x2-1][y2]||inp[x1][y1+1]==inp[x2-1][y2]||inp[x1+1][y1]==inp[x2][y2-1];
}
int o[6];
bool work()
{
    if(o[0]!=my_test(0,0,2,1))return 0;
    if(o[1]!=my_test(0,0,1,2))return 0;
    if(o[2]!=my_test(1,0,2,2))return 0;
    if(o[3]!=my_test(0,1,2,2))return 0;

    if(o[4]!=(inp[1][0]==inp[1][2]))return 0;
    if(o[5]!=(inp[0][1]==inp[2][1]))return 0;

    return 1;
}
void solve(int i)
{
    for(int p=0;p<3;p++)
        for(int q=0;q<3;q++)
        if((p+q)%2==0)
            inp[p][q]=output[p+i][q+i];

    o[0]=ask(i,i,i+2,i+1);
    o[1]=ask(i,i,i+1,i+2);
    o[2]=ask(i+1,i,i+2,i+2);
    o[3]=ask(i,i+1,i+2,i+2);

    o[4]=ask(i+1,i,i+1,i+2);
    o[5]=ask(i,i+1,i+2,i+1);

    for(int a=0;a<2;a++)
        for(int b=0;b<2;b++)
            for(int c=0;c<2;c++)
                for(int d=0;d<2;d++)
                {
                    inp[0][1]=a;
                    inp[1][0]=b;
                    inp[1][2]=c;
                    inp[2][1]=d;

                    if(work())
                    {
                        output[i+0][i+1]=a;
                        output[i+1][i+0]=b;
                        output[i+1][i+2]=c;
                        output[i+2][i+1]=d;

                        //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                        return;
                    }
                }
    assert(0==1);
}
int add_x[4]={0,0,2,-2};
int add_y[4]={2,-2,0,0};
void dfs(int x,int y,int val)
{
    if(output[x][y]!=-1)return;
    output[x][y]=val;
    for(int i=0;i<4;i++)
    {
        int x_=x+add_x[i];
        int y_=y+add_y[i];

        if(1<=x_&&x_<=n&&1<=y_&&y_<=n)
        {
            if(output[x_][y_]==-1)
            {
                int now=ask(x,y,x_,y_);
                if(now==1)dfs(x_,y_,val);
                else dfs(x_,y_,!val);
            }
        }
    }
}
int main()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        output[i][j]=-1;

    output[1][1]=1;
    output[n][n]=0;

    for(int i=3;i<=n;i=i+2)
    {
        if(ask(1,i-2,1,i))output[1][i]=output[1][i-2];
        else output[1][i]=!output[1][i-2];
    }

    for(int i=3;i<=n;i=i+2)
    {
        if(ask(i-2,1,i,1))output[i][1]=output[i-2][1];
        else output[i][1]=!output[i-2][1];
    }


    for(int i=2;i<=n;i++)
        for(int j=2;j<=n;j++)
            if((i+j)%2==0&&output[i][j]==-1)
            {
                if(ask(i-1,j-1,i,j))output[i][j]=output[i-1][j-1];
                else output[i][j]=!output[i-1][j-1];
            }

    //print();

    for(int i=1;i<=n;i++)
        if(output[i][i]==1&&output[i+2][i+2]==0)
        {
            solve(i);

            int mem=output[i+1][i];
            output[i+1][i]=-1;
            dfs(i+1,i,mem);


            mem=output[i][i+1];
            output[i][i+1]=-1;
            dfs(i,i+1,mem);

            break;
        }
    print();
    return 0;
}