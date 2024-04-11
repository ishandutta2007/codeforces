#include<bits/stdc++.h>
using namespace std;
double f[1002],k;
main(){
    int n,k;
    cin>>n>>k;
    while(n--)
    {
        for(int x=1;x<=1000;x++)
        f[x]*=1.0/k*(x/(x+1.0)+k-1.0),f[x]+=(x/2.0+(f[x+1]+x)/(x+1.0))/k;
    }
    printf("%.10f",k*f[1]);
}