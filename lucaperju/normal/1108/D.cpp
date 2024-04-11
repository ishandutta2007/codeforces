#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
//int v[200005];
char v[200005];
long long d[200005][3];
char rz[200005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie();cout.tie();
    long long n,k,i,j=0,cnt=0,pzs=1,psj=1,cur=1,pz,t,mn=9999999999;
    cin>>n>>ws>>v;
    for(i=0;i<n;++i)
    {
        if(i==0)
        {
            if(v[i]=='R')
                d[i][1]=d[i][2]=1;
            if(v[i]=='G')
                d[i][0]=d[i][2]=1;
            if(v[i]=='B')
                d[i][1]=d[i][0]=1;
            continue;
        }
        if(v[i]!='R')
            d[i][0]=1+min(d[i-1][1],d[i-1][2]);
        else
            d[i][0]=min(d[i-1][1],d[i-1][2]);
        if(v[i]!='G')
            d[i][1]=1+min(d[i-1][0],d[i-1][2]);
        else
            d[i][1]=min(d[i-1][0],d[i-1][2]);
        if(v[i]!='B')
            d[i][2]=1+min(d[i-1][1],d[i-1][0]);
        else
            d[i][2]=min(d[i-1][1],d[i-1][0]);
    }
    for(i=0;i<3;++i)
        mn=min(mn,d[n-1][i]);
    cout<<mn<<'\n';
    for(i=n-1;i>=0;--i)
    {
        if(d[i][0]==mn && (i==n-1 || rz[i+1]!='R'))
        {
            rz[i]='R';
            if(v[i]!='R')
                --mn;
        }
        else
        if(d[i][1]==mn && (i==n-1 || rz[i+1]!='G'))
        {
            rz[i]='G';
            if(v[i]!='G')
                --mn;
        }
        else
        if(d[i][2]==mn && (i==n-1 || rz[i+1]!='B'))
        {
            rz[i]='B';
            if(v[i]!='B')
                --mn;
        }
    }
    for(i=0;i<n;++i)
        cout<<rz[i];
    return 0;
}