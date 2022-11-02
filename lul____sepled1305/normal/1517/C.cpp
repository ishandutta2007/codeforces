#include<bits/stdc++.h>
using namespace std;
int B[500][500],n;

void bfs(int x, int y, int num, int val)
{
    if(num == 0)
        return;
    if(num >= 1)
    {
        B[x][y] = val;
        if(x != n-1 && B[x+1][y] == 0)
            bfs(x+1,y,num-1,val);
        else
            bfs(x,y-1,num-1,val);
    }
}

int main()
{
    cin>>n;
    int v[n];
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=n-1;i>=0;i--)
    {
        bfs(i,i,v[i],v[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
            cout<<B[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}