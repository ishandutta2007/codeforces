#include <bits/stdc++.h>
#define maxn 1000005
#define CLMS ""
#define ft first
#define sd second
#define PB push_back
#define MP make_pair
#define endl "\n"
using namespace std;
long a[maxn];
long n;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(long i=1;i<=n;++i)
    {
        cin >> a[i];
    }
    long dem=0;
    for(long i=2;i<n;++i)
    {
        if(a[i]==0 && a[i+1]==1 &&a[i-1]==1)
        {
            dem++;
            a[i+1]=0;
        }
    }
    cout << dem;
    return 0;
}