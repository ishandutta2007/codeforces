# include <iostream>
# include <cstdio>
# include <algorithm>
using namespace std;

int a[200];
int main()
{
    int n, m, d;
    cin >> n >> d;
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    for(int i=1; i<n; i++) a[i] += a[i-1];
    cin >> m;
    if(m<=n) cout << a[m-1] << endl;
    else cout << a[n-1] - (m - n)*d << endl;
    return 0;
}