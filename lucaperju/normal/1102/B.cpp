#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
long long v[200005],fv[5005];
vector <int> vv[5005];
char c[200005];
int main()
{
    long long i,j,mx=-999999999999LL,pz,n,k,cur=1;
    long long mn=-mx;
    cin>>n>>k;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        ++fv[v[i]];
        if(fv[v[i]]>k)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES\n";
    for(i=1;i<=5000;++i)
    {
        for(j=0;j<fv[i];++j)
        {
            vv[i].push_back(cur);
            ++cur;
            if(cur>k)
                cur=1;
        }
    }
    for(i=1;i<=n;++i)
    {
        cout<<vv[v[i]][vv[v[i]].size()-1]<<' ';
        vv[v[i]].pop_back();
    }
}