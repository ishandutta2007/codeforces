#include <bits/stdc++.h>
using namespace std;
int v[10][10];
void change (int i, int j)
{
    v[i][j]=v[i][j]%9+1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i,j=0,t,mx=0;
    cin>>t;
    while(t--)
    {
        for(i=1;i<=9;++i)
            for(j=1;j<=9;++j)
            {
                char c;
                cin>>c;
                v[i][j]=c-'0';
            }
        change(1,1);
        change(2,4);
        change(3,7);
        change(4,2);
        change(5,5);
        change(6,8);
        change(7,3);
        change(8,6);
        change(9,9);
        for(i=1;i<=9;++i)
        {
            for(j=1;j<=9;++j)
                cout<<v[i][j];
            cout<<'\n';
        }
    }
    return 0;
}