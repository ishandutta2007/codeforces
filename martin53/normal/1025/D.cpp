#include<bits/stdc++.h>
using namespace std;
const int nmax=7e2+5;
int n,arr[nmax];
int can[nmax][nmax][2];//can k be root of the subtree [i,j]
bool G[nmax][nmax];
bool rec(int l,int r,bool which)
{
    if(l>r)return 1;
    if(can[l][r][which]!=-1)return can[l][r][which];
    bool ok=0;
    int other=(which==0?l-1:r+1);
    for(int i=l;i<=r;i++)
        if(G[i][other])
        if(rec(l,i-1,1)&&rec(i+1,r,0))
        {
            can[l][r][which]=1;
            return 1;
        }
    can[l][r][which]=0;
    return 0;
}
int main()
{
memset(can,-1,sizeof(can));
cin>>n;
for(int i=1;i<=n;i++)cin>>arr[i];
for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        G[i][j]=(__gcd(arr[i],arr[j])>1);
for(int i=1;i<=n;i++)
    if(rec(1,i-1,1)&&rec(i+1,n,0))
    {
    cout<<"Yes"<<endl;
    return 0;
    }
cout<<"No"<<endl;
return 0;
}