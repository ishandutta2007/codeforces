#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
long long n,k;
///x^2-x+(2n-2k)==0
int main(){
    scanf("%lld%lld",&n,&k);
    double fuck=((sqrt(9.0+4.0*(double)(2*k+2*n)))-3.0)/2.0;
     fuck=(double)(n)-fuck;
    printf("%.0f",fuck);

}
/*
    Good Luck
        -Lucina
*/