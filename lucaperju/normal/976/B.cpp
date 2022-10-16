#include <iostream>

using namespace std;

int main()
{
    long long n,m,k,ok=0,poz;
    cin>>n>>m>>k;
    if(k<n)
        cout<<k+1<<' '<<1;
    else
    {
        k=k-n+1;
        ok=0;
        poz=n;
        k--;
        m--;
        if(k==0)
            cout<<n<<' '<<2;
        else
        {
            poz-=k/m;
            ok=ok+k/m%2;
            k-=k/m*m;
            while(k>=0)
            {
                if(k-m+1<=0)
                {
                    if(ok==0)
                        cout<<poz<<' '<<2+k;
                    else
                        cout<<poz<<' '<<m-k+1;
                }
                poz--;
                k=k-m;
                ok=1-ok;
            }
        }
    }
    return 0;
}