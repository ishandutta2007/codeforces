#include<bits/stdc++.h>
using namespace std;
int main() {
    int t,n;
    cin>>t;
    while(t--)cin>>n,printf("%.9f\n",1/tan(asin(1)/n));
}