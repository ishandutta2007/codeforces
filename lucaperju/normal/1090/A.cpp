#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
vector <long long> v[200005];
int main()
{
    long long t,n,i,j=0,k=0,s=0,okneg=0,cnt=0,mx=-99999999999999LL,m,cur=0,pz,a,b,vl1=1,ok,sus=1,jos=1;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>m;
        for(j=0;j<m;++j)
        {
            cin>>a;
            v[i].push_back(a);
            if(a>mx)
                mx=a;
        }
    }
    for(i=1;i<=n;++i)
    {
        cur=0;
        for(j=0;j<v[i].size();++j)
            if(v[i][j]>cur)
                cur=v[i][j];
        s+=v[i].size()*1LL*(mx-cur);
    }
    cout<<s;
}