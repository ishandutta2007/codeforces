#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t;
double n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lf",&n);
        n *= 2;

        double deg = 90 - (360.0/n/2/2);

        double cs = 1/cos(deg*acos(-1)/180)/4;

        printf("%.10f\n",cs*2);

    }
}