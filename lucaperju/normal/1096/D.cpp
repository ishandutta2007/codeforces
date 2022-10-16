#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iomanip>
using namespace std;
char v[100005];
long long cst[100005];
long long d[100005][5];
int main()
{
    long long t,n,i,j=0,k=0,s=1,okneg=0,cnt=0,mn=99999999999999LL,m,cur,pz,a,b,vl1=1,ok;
    cin>>n>>ws>>(v+1);
    for(i=1;i<=n;++i)
    {
        cin>>cst[i];
        if(v[i]=='h')
            d[i][1]+=cst[i];
        d[i][1]+=d[i-1][1];
        if(v[i]=='a')
            d[i][2]+=cst[i];
        d[i][2]+=min(d[i-1][2],d[i-1][1]);
        if(v[i]=='r')
            d[i][3]+=cst[i];
        d[i][3]+=min(min(d[i-1][2],d[i-1][1]),d[i-1][3]);
        if(v[i]=='d')
            d[i][4]+=cst[i];
        d[i][4]+=min(min(d[i-1][2],d[i-1][1]),min(d[i-1][3],d[i-1][4]));
    }
    cout<<min(min(d[n][2],d[n][1]),min(d[n][3],d[n][4]));
}