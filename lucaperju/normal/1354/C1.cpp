#include <bits/stdc++.h>

using namespace std;
char v[200005];
int pz[200005];
const double pi=3.141592653589793238;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long i,t,j,k,mx,p,mxx=0,s,q;
    cin>>t;
    while(t--)
    {
        double n;
        cin>>n;
        n*=2;
        cout<<fixed<<setprecision(7)<<(double)(1/tan(pi/n))<<'\n';
    }
    return 0;
}