// c++1.cpp:      .
//

#include "math.h"
#include "iostream"

#include "algorithm"

int nod (int a, int b){
    while (a>0 && b>0) if (a>b) a=a%b; else b=b%a;
    if (a>b) return a; else return b;
}
int nok ( int a, int b){
    return(a*b)/nod(a,b);
}
int main()
{
    long a,b,c,d,n,k;
    std::cin>>a>>b>>c>>d>>n;
     k=n/a+n/b+n/c+n/d-n/nok(a,b)-n/nok(a,c)-n/nok(a,d)-n/nok(b,c)-n/nok(b,d)-n/nok(c,d)+n/nok(nok(a,b),c)
         +n/nok(nok(a,b),d)+n/nok(nok(a,c),d)+n/nok(nok(b,c),d)-n/nok(nok(nok(a,b),c),d);
     std::cout<<k;

    return 0;
}