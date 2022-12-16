#include<bits/stdc++.h>
using namespace std;
const int nmax=600+42;
int n;
int le[nmax],ri[nmax];
int can[nmax][nmax];
int where[nmax][nmax];
bool rec(int l,int r)
{
    if(l>r)return 1;
    if(can[l][r]!=-1)return can[l][r];
    for(int dist=1;dist<=ri[l]&&l+dist/2<=r;dist=dist+2)
        if(le[l]<=dist)
        {
            if(rec(l+1,l+dist/2)&&rec(l+dist/2+1,r))
            {
                //cout<<l<<" "<<r<<" -> "<<dist<<endl;
                where[l][r]=dist;
                can[l][r]=1;
                return 1;
            }
        }
    can[l][r]=0;
    return 0;
}
void go(int l,int r)
{
    //cout<<l<<" "<<r<<endl;
    if(l>r)return;
    //cout<<l<<" "<<r<<endl;
    cout<<"(";
    go(l+1,l+where[l][r]/2);
    cout<<")";
    go(l+where[l][r]/2+1,r);
}
int main()
{
memset(can,-1,sizeof(can));
cin>>n;
for(int i=1;i<=n;i++)cin>>le[i]>>ri[i];

if(rec(1,n)==0)
{
     cout<<"IMPOSSIBLE"<<endl;
     return 0;
}

go(1,n);
return 0;
}