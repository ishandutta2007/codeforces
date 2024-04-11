#include <iostream>
#include <ios>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int n, a[200005], i;
    cin>>n;
    for (i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (i = 0; i < n - 1; i++)
    {
        if (a[i] < 0) {cout<<"NO"; return 0;}
        if (a[i] % 2) a[i+1]--;
    }
    if (a[n-1] % 2 == 0) cout<<"YES"; else cout<<"NO";
}