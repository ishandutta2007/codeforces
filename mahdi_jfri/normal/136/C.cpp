#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+20;
#define ll long long
int a[maxn];
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a,a+n);
    a[n-1]=(a[n-1]==1? 2:1);
    sort(a,a+n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}