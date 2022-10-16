#include <iostream>

using namespace std;
int v[20],fv[20];;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>v[i];
    for(int i=1;i<=m;++i)
    {
        int a;
        cin>>a;
        fv[a]++;
    }
    for(int i=1;i<=n;++i)
    {
        if(fv[v[i]])
            cout<<v[i]<<' ';
    }
    return 0;
}