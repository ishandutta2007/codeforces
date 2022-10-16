#include <iostream>

using namespace std;
bool verif (long long i)
{
    long long pas=1<<4,k=0,ck;
    while(pas)
    {
        ck=k+pas;
        if(((1<<ck)-1)*1LL*(1<<(ck-1))<=i)
            k+=pas;
        pas>>=1;
    }
    if(((1<<k)-1)*1LL*(1<<(k-1))==i)
        return true;
    return false;
}
int main()
{
    long long n,i,j,mx=1;
    cin>>n;
    for(i=1;i*i<=n;++i)
    {
        if(n%i==0)
        {
            if(verif(i))
                if(i>mx)
                    mx=i;
            if(verif(n/i))
                if(n/i>mx)
                    mx=n/i;
        }
    }
    cout<<mx;
    return 0;
}