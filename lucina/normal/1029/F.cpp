#include<stdio.h>
#include<algorithm>
using namespace std;
long long a,b,c;
long long m=5e18;
long long ans;
int main(){
    scanf("%lld %lld",&a,&b);
    c=a+b;
    long long i;
    for( i=1;i*i<=c;i++){
        if(a%i==0) m=min(m,a/i);
        if(b%i==0) m=min(m,b/i);
        if(c%i==0&&c/i>=m) ans=2*(i+c/i);
    }
    printf("%lld\n",ans);
}