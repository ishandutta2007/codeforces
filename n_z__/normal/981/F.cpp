#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,l,a[200001],b[600001];
bool check(int m)
{
    int L=1,R=3*n;
    for(int x=1;x<=n;x++)
    {
        while(b[L]<a[x]-m)L++;
        while(b[R]>a[x]+m)R--;
        L++,R++;
    }
    return L<=R;
}
main()
{
    auto st=clock();
    cin>>n>>l;
    for(int x=1;x<=n;x++)
    cin>>a[x];
    for(int x=1;x<=n;x++)
    cin>>b[x],b[x+n]=b[x]-l,b[x+2*n]=b[x]+l;
    sort(a+1,a+1+n);
    sort(b+1,b+3*n+1);
    int L=0,R=l/2;
    while(L<R&&clock()-st<=2.95*CLOCKS_PER_SEC)
    {
        int m=(L+R)/2;
        if(check(m))R=m;else L=m+1;
    }
    cout<<L<<endl;
}