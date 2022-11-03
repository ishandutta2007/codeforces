#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int maxn = 1e5+20;
int q , p , res;
int main()
{
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> p >> q;
        if (q-p > 1)
            res++;
    }
    cout << res;
}