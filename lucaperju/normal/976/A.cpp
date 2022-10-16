#include <iostream>

using namespace std;

int main()
{
    long long n,cnt=0,i;
    char c;
    cin>>n>>ws;
    for(i=1;i<=n;i++)
    {
        cin>>c;
        if(c=='0')
            cnt++;
    }
    if(n==1 && cnt==1)
        cout<<0;
    else
    {
        cout<<1;
        for(i=1;i<=cnt;i++)
            cout<<0;
    }
    return 0;
}