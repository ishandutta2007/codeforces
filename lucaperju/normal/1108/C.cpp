#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
//int v[200005];
char v[200005],m[200005],rz[200005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie();cout.tie();
    long long n,k,i,j=0,cnt=0,pzs=1,psj=1,cur=1,pz,t,mn=9999999999;
    cin>>n>>ws>>v;
    for(i=0;i<n;++i)
        if(v[i]=='R')
            v[i]=1;
        else
        if(v[i]=='G')
            v[i]=2;
        else
            v[i]=3;
    for(int ii=1;ii<=3;++ii)
        for(int jj=1;jj<=3;++jj)
            for(int kk=1;kk<=3;++kk)
            {
                if(ii==jj || ii==kk || jj==kk)
                    continue;
                m[0]=ii;
                m[1]=jj;
                m[2]=kk;
                cnt=0;
                for(i=3;i<n;++i)
                    m[i]=m[i-3];
                for(i=0;i<n;++i)
                    if(v[i]!=m[i])
                        ++cnt;
                if(cnt<mn)
                {
                    mn=cnt;
                    for(i=0;i<n;++i)
                        rz[i]=m[i];
                }
            }
    cout<<mn<<'\n';
    for(i=0;i<n;++i)
    {
        if(rz[i]==1)
            cout<<'R';
        else
            if(rz[i]==2)
                cout<<'G';
        else
            cout<<'B';
    }
    return 0;
}