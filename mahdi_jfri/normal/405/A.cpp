#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+20;
int a[maxn];
int main()
{
    int n;
    cin >> n;
    for(int i=0 ; i < n ; i++)
        cin >> a[i];
    sort(a,a+n);
    for(int i = 0 ; i < n ; i++ )
        cout << a[i] << " ";
}