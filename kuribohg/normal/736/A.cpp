#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
LL n,a,b,c,ans;
int main()
{
    cin>>n;
    a=1,b=1,c=a+b;
    while(c<=n)
    {
        a=b,b=c,c=a+b;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}