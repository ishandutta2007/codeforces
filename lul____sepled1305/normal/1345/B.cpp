#include<bits/stdc++.h>
using namespace std;
int tri_num[100005];
int pyra_num[100005];

int solve(int nn)
{
    double pp = (double) nn;
    pp = sqrt(1+24*pp);
    pp--;
    pp/=6;
    return (int) floor(pp);
}

int main()
{
    int t,i,j,k,n,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans = 0;
        while(n>=2)
        {
            int k = solve(n);
            n-=(3*k*k+k)/2;
            ans++;
        }
        cout<<ans<<"\n";
    }
}