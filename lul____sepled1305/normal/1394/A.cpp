/** Sora is the best girl. **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int N = 1e5+10;
const int MOD = 1e9+7;
int n,d,m,i,j;
long long quick[N];
long long high_quick[N];
long long maxi = 0;

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/

    cin>>n>>d>>m;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int counti  = 0;
    long long sum = 0;
    for(i=0;i<n;i++)
    {
        if(a[i]>m)
            break;
    }
    sort(a,a+i,greater<int> ());
    for(i=0;i<n;i++)
    {
        if(a[i]<=m)
            sum+=a[i];
        quick[i] = sum;
    }
    sum = 0;
    for(i=n-1;i>=0;i--)
    {
        if(a[i]>m)
            sum+=a[i];
        high_quick[i] = sum;
    }
    maxi = quick[n-1];
    for(i=1;i<=n;i++)
    {
        if((i-1)*(d+1)+1 > n)
            break;
        else
        {
            maxi = max(high_quick[n-i]+quick[n-2-(i-1)*(d+1)],maxi);
        }
    }
    i = 0;
    cout<<maxi;
    return 0;
}