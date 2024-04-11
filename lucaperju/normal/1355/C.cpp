#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long b,c,d,m,n,i,t,j,k,mx,p,mxx=0,s,rz=0,a,r;
    cin>>a>>b>>c>>d;
    rz=0;
    for(i=a;i<=b;++i)
    {
        long long st=b+i-1;
        long long dr=c+i-1;
        st=max(st,c);
        if(dr>d && st<=d)
        {
            rz+=(dr-d)*(d-c+1);
            dr=d;
        }
        else if(dr>d && st>d)
        {
            rz+=(d-c+1)*(dr-st+1);
            continue;
        }
        rz+=dr*(dr+1)/2-st*(st-1)/2-(dr-st+1)*(c-1);
    }
    cout<<rz;
    return 0;
}