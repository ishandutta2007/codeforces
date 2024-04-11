#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
bool verif (int a, int b)
{
    if((a*1LL*(a+1LL)/2+b)%2==0)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    long long m,i,j,k,s=0,t;
    cin>>t;
    while(t--)
    {
        long long a,b;
        cin>>a>>b;
        long long dif=max(a-b,b-a);
        long long pas=1LL<<30,k=0;
        long long difi=dif;
        while(pas)
        {
            if((k+pas)*1LL*(k+pas+1LL)/2LL<=dif)
                k+=pas;
            pas>>=1LL;
        }
        dif-=k*1LL*(k+1LL)/2LL;
        if(dif==0)
        {
            cout<<k<<'\n';
            continue;
        }
        for(i=1;i<=10;++i)
        {
            if(verif(k+i,difi))
            {
                cout<<k+i<<'\n';
                break;
            }
        }
    }
    return 0;
}