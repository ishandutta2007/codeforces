#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const LL MOD=1000000007;
LL n,k;
int main()
{
    cin>>n>>k;
    cout<<(n*6-1)*k<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<(i*6-1)*k<<" ";
        cout<<(i*6-3)*k<<" ";
        cout<<(i*6-5)*k<<" ";
        cout<<(i*6-4)*k<<endl;
    }
    return 0;
}