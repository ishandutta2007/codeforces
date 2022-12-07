#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
LL x,fac=1,a,b;
int main()
{
    cin>>x;
    if(x==1||x==2) {puts("-1");return 0;}
    while(x%2==0&&x!=4) x>>=1,fac<<=1;
    if(x==4) cout<<3LL*fac<<" "<<5LL*fac;
    else a=(x*x+1)/2,b=(x*x-1)/2,cout<<a*fac<<" "<<b*fac<<endl;
    return 0;
}