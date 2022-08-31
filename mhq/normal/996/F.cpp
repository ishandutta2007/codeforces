#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(false);
    cout<<setprecision(20);
    int n;
    cin>>n;
    n=pow(2,n);
    int q;
    cin>>q;
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum += a[i];
    }
    cout<<sum/(n*1.0)<<'\n';
    for(int i=0;i<q;i++){
        int j=0;
        cin>>j;
        ld a1;
        cin>>a1;
        sum += a1;
        sum -= a[j];
        a[j]=a1;
        cout<<sum/(n*1.0)<<'\n';
    }
    return 0;
}