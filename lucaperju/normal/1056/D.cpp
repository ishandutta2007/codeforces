#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
vector <int>v[100005];
int rez[100005];
int main()
{
    long long n,i,j,a;
    cin>>n;
    for(i=2;i<=n;++i)
    {
        cin>>a;
        v[a].push_back(i);
    }
    for(i=1;i<=n;++i)
        if(v[i].size()==0)
            rez[i]=1;
    for(i=n;i>=1;--i)
    {
        int s=0;
        for(j=0;j<v[i].size();++j)
            s+=rez[v[i][j]];
        if(v[i].size())
        rez[i]=s;
    }
    sort(rez+1,rez+n+1);
    for(i=1;i<=n;++i)
        cout<<rez[i]<<' ';
    return 0;
}