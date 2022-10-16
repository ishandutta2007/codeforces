#include <bits/stdc++.h>
using namespace std;
int rz[105];
long long na,nb,a,b;
void query (int x)
{
    cout<<"+ "<<x<<'\n';
    cout.flush();
    cin>>na>>nb;
    int ca,cb;
    ca=na;
    cb=nb;
    na-=a;
    nb-=b;
    a=ca;
    b=cb;
}
int getval (int val)
{
    if(val==0)
        return -1;
    for(int i=1;i<=110;++i)
        if(i*(i-1)/2==val)
            return i;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long i,j,mx=0,s=0,ok,n;
    long long k=0,t,d;
    cin>>n>>a>>b;
    for(i=1;i<=n;++i)
        rz[i]=-1;
    query(1);
    rz[1]=getval(na);
    if(nb)
        rz[2]=rz[3]=1;
    query(2);
    rz[2]=max(getval(na),rz[2]);
    if(nb)
        rz[3]=max(rz[3],1);
    else
        rz[3]=0;
    query(3);
    int ra=na,rb=nb;
    rz[3]=max(rz[3],getval(na));
    query(1);
    if(rz[1]==-1)
    if(na==0)
        rz[1]=0;
    else
        rz[1]=max(rz[1],1);
    rz[2]=nb/(rz[3]+1)-1;
    for(i=4;i<n;++i)
    {
        if(rb-(rz[i-2]+1)*(rz[i-3]+1)==0)
            rz[i]=0;
        else
            rz[i]=1;
        query(i);
        rz[i]=max(rz[i],getval(na));
        ra=na;
        rb=nb;
    }
    rz[n]=(rb-(rz[n-2]+1)*(rz[n-3]+1))/(rz[n-2]+1);
    cout<<"! ";
    for(i=1;i<=n;++i)
        cout<<rz[i]<<' ';
    cout<<'\n';
    cout.flush();
    return 0;
}