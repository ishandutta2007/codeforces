#include <bits/stdc++.h>

using namespace std;
int a[100000];
int n;
int k;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+ n);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> k;
        int p = upper_bound(a, a+n,k)-a;
        if (p==n)
            cout << n<<endl;
        else
            cout << p<<endl;

    }
    return 0;
}