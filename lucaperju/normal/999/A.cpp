#include <iostream>

using namespace std;
long long v[105];
int main()
{
    int n,i,cnt=0,k;
    cin>>n>>k;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=1;i<=n;++i)
    {
        if(v[i]<=k)
        {
            ++cnt;
            v[i]=9999999;
        }
        else
            break;
    }
    for(i=n;i>=1;--i)
    {
        if(v[i]<=k)
        {
            ++cnt;
            v[i]=9999999;
        }
        else
            break;
    }
    cout<<cnt;
    return 0;
}