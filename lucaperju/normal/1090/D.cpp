#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
vector <int> v[100003];
int fv[100003];
int main()
{
    long long t,n,i,j=0,k=0,s=0,okneg=0,cnt=0,mx=-99999999999999LL,m,cur=0,pz2,pz1,a,b,vl1=1,ok=0,sus=1,jos=1;
    cin>>n>>k;
    if(k==n*1LL*(n-1)/2)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    for(i=1;i<=k;++i)
    {
        cin>>a>>b;
        ++fv[a];
        ++fv[b];
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i=1;i<=n;++i)
        if(fv[i]!=n-1)
        {
            pz1=i;
            break;
        }
    for(i=1;i<=n;++i)
        fv[i]=0;
    for(i=0;i<v[pz1].size();++i)
        fv[v[pz1][i]]++;
    ++fv[pz1];
    for(i=1;i<=n;++i)
        if(!fv[i])
        {
            pz2=i;
            break;
        }
    k=2;
    for(i=1;i<=n;++i)
    {
        if(i!=pz1 && i!=pz2)
            cout<<++k<<' ';
        else
        if(i==pz1)
            cout<<1<<' ';
        else
            cout<<2<<' ';
    }
    cout<<'\n';
    k=2;
    for(i=1;i<=n;++i)
    {
        if(i==pz1 || i==pz2)
            cout<<1<<' ';
        else
            cout<<++k<<' ';
    }

}