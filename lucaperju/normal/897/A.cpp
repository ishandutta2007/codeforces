#include <iostream>

using namespace std;
char v[105];
int main()
{
    int n,m,a,b,i,j;
    char c1,c2;
    cin>>n>>m>>ws;
    cin>>v;
    for(i=1;i<=m;++i)
    {
        cin>>a>>b>>c1>>c2;
        a--;
        b--;
        for(j=a;j<=b;++j)
        {
            if(v[j]==c1)
                v[j]=c2;
        }
    }
    for(i=0;i<n;++i)
        cout<<v[i];
    return 0;
}