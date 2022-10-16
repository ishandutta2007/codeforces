#include <bits/stdc++.h>

using namespace std;
int fv[30];
int cmmdc (int a, int b)
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long t,m,k,i,j,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0,n;
    cin>>t;
    while(t--)
    {
        for(i=0;i<=28;++i)
            fv[i]=0;
        int k;
        cin>>n>>k;
        int rz=1;
        for(i=1;i<=n;++i)
        {
            char c;
            cin>>c;
            ++fv[c-'a'];
            if(k%i==0)
                rz=i;
        }
        int rzf=rz;
        for(;rz<=n;++rz)
        {
            int cnt=0;
            int cmdc=cmmdc(rz,k);
            for(i=0;i<=27;++i)
            {
                cnt+=fv[i]-fv[i]%(rz/cmdc);
            }
            if(cnt>=rz)
                rzf=rz;
        }
        cout<<rzf<<'\n';
    }
    return 0;
}