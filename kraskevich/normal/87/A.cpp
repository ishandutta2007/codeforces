#include <iostream>
using namespace std;typedef long long i64; i64 gcd(i64 a,i64 b){return b?gcd(b,a%b):a;}
int main(){ios_base::sync_with_stdio(0);i64 a,b;cin>>a>>b;i64 lcm=a*b/gcd(a,b),mx=max(a,b),mn=min(a,b),sd=0,sm=0;
for(i64 i=0;i<lcm/mx;++i){i64 add=mx*(i+1)%mn;if(a>b)sd+=(add?add:mn);else sm+=(add?add:mn);}
if(a>b)sm=lcm-sd;else sd=lcm-sm;if(sd>sm)cout<<"Dasha";if(sd<sm)cout<<"Masha";if(sd==sm)cout<<"Equal";};