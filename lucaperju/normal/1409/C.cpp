#include <bits/stdc++.h>
using namespace std;
int cmmdc(int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t,i,j,k;
    cin>>t;
    while(t--)
    {
        long long n,a,b,x,y;
        cin>>n>>a>>b;
        int pz=b;
        int c=b-a;
        for(i=1;i<=c;++i)
        {
            if(c%i==0 && b-(n-1)*i<=a)
                break;
        }
        c=i;
        while(n && pz>0)
        {
            --n;
            cout<<pz<<' ';
            pz-=c;
        }
        pz=b+c;
        while(n)
        {
            --n;
            cout<<pz<<' ';
            pz+=c;
        }
        cout<<'\n';
    }
}