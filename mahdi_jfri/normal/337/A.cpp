#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=55;
int a[maxn];
int _min=1e5;
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }
    sort(a,a+m);
    n--;
    for(int i=0;i<m-n;i++)
    {
        _min=min(a[i+n]-a[i],_min);
    }
    cout<<_min;
}