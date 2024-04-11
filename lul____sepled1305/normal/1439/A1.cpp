#include<bits/stdc++.h>
using namespace std;
int T;

struct op
{
    int x1,x2,x3,y1,y2,y3;

    op(int a, int b, int c, int d, int e, int f)
    {
        x1 = a, y1 = b, x2 = c, y2 = d, x3 = e, y3 = f;
    }
};

void change(op a, string B[], vector<op> &v)
{
    v.push_back(a);
    B[a.x1][a.y1] = (B[a.x1][a.y1] - '0' + 1)%2 + '0';
    B[a.x2][a.y2] = (B[a.x2][a.y2] - '0' + 1)%2 + '0';
    B[a.x3][a.y3] = (B[a.x3][a.y3] - '0' + 1)%2 + '0';
}

void recur(int row,string B[], int n, int m, vector<op> &v)
{
    int pointer = 0;
    while(pointer != m-2)
    {
        if(B[row][pointer] == '0' && B[row+1][pointer] == '0')
            ;
        else if(B[row][pointer] == '1' && B[row+1][pointer] == '0')
            change(op(row,pointer,row,pointer+1,row+1,pointer+1),B,v);
        else if(B[row][pointer] == '0' && B[row+1][pointer] == '1')
            change(op(row+1,pointer,row,pointer+1,row+1,pointer+1),B,v);
        else
            change(op(row+1,pointer,row,pointer,row+1,pointer+1),B,v);
        pointer++;
    }
    if(row != n-2)
    {
        if(B[row][pointer] == '0' && B[row][pointer+1] == '0')
            ;
        else if(B[row][pointer] == '1' && B[row][pointer+1] == '0')
            change(op(row,pointer,row+1,pointer,row+1,pointer+1),B,v);
        else if(B[row][pointer] == '0' && B[row][pointer+1] == '1')
            change(op(row+1,pointer,row,pointer+1,row+1,pointer+1),B,v);
        else
            change(op(row+1,pointer,row,pointer,row,pointer+1),B,v);

        recur(row+1,B,n,m,v);
    }
    else
    {
        int seed = B[row][pointer]+B[row][pointer+1]+B[row+1][pointer]+B[row+1][pointer+1] - '0' - '0'-'0'-'0';
        if(seed == 4)
            change(op(row,pointer,row+1,pointer,row+1,pointer+1),B,v);

        seed = B[row][pointer]+B[row][pointer+1]+B[row+1][pointer]+B[row+1][pointer+1] - '0' - '0'-'0'-'0';
        if(seed == 1)
        {
            if(B[row][pointer+1] == '1')
                change(op(row,pointer+1,row+1,pointer,row+1,pointer+1),B,v);
            else
                change(op(row,pointer,row+1,pointer,row+1,pointer+1),B,v);
        }

        seed = B[row][pointer]+B[row][pointer+1]+B[row+1][pointer]+B[row+1][pointer+1] - '0' - '0'-'0'-'0';
        if(seed == 2)
        {
            if(B[row][pointer] == '0')
            {
                if(B[row][pointer+1] == '0')
                    change(op(row,pointer+1,row,pointer,row+1,pointer+1),B,v);
                else if(B[row+1][pointer] == '0')
                    change(op(row,pointer,row+1,pointer,row+1,pointer+1),B,v);
                else
                    change(op(row,pointer,row+1,pointer,row+1,pointer+1),B,v);
            }
            else
                change(op(row,pointer+1,row+1,pointer,row+1,pointer+1),B,v);
        }

        seed = B[row][pointer]+B[row][pointer+1]+B[row+1][pointer]+B[row+1][pointer+1] - '0' - '0'-'0'-'0';
        if(seed == 3)
        {
            if(B[row][pointer] == '0')
                change(op(row,pointer+1,row+1,pointer,row+1,pointer+1),B,v);
            else if(B[row+1][pointer] == '0')
                change(op(row,pointer+1,row,pointer,row+1,pointer+1),B,v);
            else if(B[row][pointer+1] == '0')
                change(op(row+1,pointer,row,pointer,row+1,pointer+1),B,v);
            else
                change(op(row+1,pointer,row,pointer,row,pointer+1),B,v);
        }
    }
}

void solve()
{
    int n,m,i,j;
    vector<op> v;
    cin>>n>>m;
    string B[n];
    for(i=0;i<n;i++)
    {
        cin>>B[i];
    }
    recur(0,B,n,m,v);
    cout<<v.size()<<endl;
    for(auto it: v)
        cout<<it.x1+1<<' '<<it.y1+1<<' '<<it.x2+1<<' '<<it.y2+1<<' '<<it.x3+1<<' '<<it.y3+1<<endl;
}

int main()
{
    cin>>T;
    while(T--)
    {
        solve();
    }
}