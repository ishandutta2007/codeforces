#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=1000000009;
main()
{
    int n;
    cin>>n;
    int a=1,b=2,c=4;
    while(n-=2)
    (c*=a)%=p,(b+=c)%=p,((a*=2)+=3)%=p;
    cout<<(b*b%p+1)*2%p<<endl;
}