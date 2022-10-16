#include <iostream>
#include <algorithm>
using namespace std;
int v[2005][2005],fv[2005],n,m,cr[2005];
void citire (int n, int m)
{
    char c;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin>>c;
            v[i][j]=c-'0';
            if(c=='1')
                fv[j]++;
        }
    }
}
bool rez ()
{
    int i,j,ok;
    for(j=1;j<=n;++j)
    {
        ok=0;
        for(i=1;i<=m;++i)
        {
            cr[i]=fv[i]-v[j][i];
            if(cr[i]==0)
            {
                ok=1;
                break;
            }
        }
        if(ok==0)
            return true;
    }
    return false;
}
int main()
{
    cin>>n>>m;
    citire(n,m);
    if(rez())
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}