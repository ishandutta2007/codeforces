#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>



using namespace std;
typedef long long ll;

int main()
{
    ll m[505][505];
    ll n, k;
    cin>>n>>k;
    ll t=n*n;
    for (int i=n-1;i>=0;i--)
        for (int j=n-1;j>=k-1;j--)
        {
            m[i][j]=t;
            t--;
        }
    t=1;
    for (int i=0;i<n;i++)
        for (int j=0;j<k-1;j++)
        {
            m[i][j]=t;
            t++;
        }
    ll sum=0;
    for (int j=0;j<n;j++) sum+=m[j][k-1];
    cout<<sum<<endl;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++) cout<<m[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}