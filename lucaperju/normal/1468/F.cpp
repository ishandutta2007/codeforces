#include <bits/stdc++.h>
using namespace std;
std::map<long long,std::map<long long,int> > m;
long long cmmdc (long long a, long long b)
{
    long long r=0;
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
    long long t,n,i,j,mod;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long s=0;
        for(i=1;i<=n;++i)
        {
            long long a,b,c,d;
            cin>>a>>b>>c>>d;
            a=c-a;
            b=d-b;
            if(a==0)
            {
                if(b>0)
                    b=1;
                else
                    b=-1;
            }
            else
            if(b==0)
            {
                if(a>0)
                    a=1;
                else
                    a=-1;
            }
            else
            {
                c=cmmdc(max(a,-a),max(b,-b));
                a/=c;
                b/=c;
            }
            ++m[-a][-b];
            s+=m[a][b];
        }
        m.clear();
        cout<<s<<'\n';
    }
    return 0;
}