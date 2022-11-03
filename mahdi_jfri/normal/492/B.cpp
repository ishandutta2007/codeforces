#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+20;
int a[maxn];
int main()
{
    int n , l;
    cin >> n >> l;
    for(int i=0 ; i < n ;i++)
        cin >> a[i];
    n++;
    a[n]=l;
    sort(a,a+n);
    double ans=0;
    ans=a[1];
    double k = 0;
    for(int i=2; i <= n; i++)
    {
        k=a[i]-a[i-1];
        if(i != n)
            k/=2;
        ans=max(k,ans);
    }

    printf("%.17f",ans);
}