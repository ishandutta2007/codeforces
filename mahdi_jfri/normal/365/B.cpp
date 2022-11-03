#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int a[maxn], _max = 2, res = 2;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 2; i < n; i++)
    {
        if(a[i] == a[i - 1] + a[i - 2])
            res++;
        else
            _max = max(res , _max) , res = 2;
    }
    _max = max(res , _max);
    if(_max > n)
        _max = n;
    cout << _max;
}