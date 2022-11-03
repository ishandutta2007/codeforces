#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
ll res , k , a , b;
int main()
{
    cin >> k >> a >> b;
    if((a < k && b < k) || (a%k && b < k) || (a < k && b%k))
    {
        cout << -1;
        return 0;
    }
    cout << a / k + b / k;
}