#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t;
ll n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        n *= 2;
        double s1 = 0, s2 = 0;

        double deg2 = 90 - (360.0/n/2);
        printf("%.10f\n",tan(deg2*acos(-1)/180));

    }
}