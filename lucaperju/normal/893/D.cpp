#include <iostream>

using namespace std;

int main()
{
    long long n,d,i,mx=0,a,sc=0,cnt=0;
    cin>>n>>d;
    for(i=1;i<=n;++i)
    {
        cin>>a;
        if(a!=0)
            sc+=a;
        else if(sc<0)
        {
            if(sc+(d-mx)>=0 && cnt)
            {
                mx+=(0-sc);
                sc=0;
            }
            else
            {
                mx=sc=0;
                ++cnt;
            }
        }
        if(sc>mx)
            mx=sc;
        if(sc>d)
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<cnt;
    return 0;
}