#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
LL n;
int main()
{
    scanf("%I64d",&n);
    cout<<2<<endl;
    for(LL i=2;i<=n;i++)
        cout<<(i+1)*(i+1)*i-(i-1)<<endl;
    return 0;
}