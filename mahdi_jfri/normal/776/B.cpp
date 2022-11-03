#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
vector<int> p;
int is[maxn];
int _max;
int main()
{
    int n;
    cin >> n;
    for(ll i = 2; i <= n + 1; i++)
    {
        if(is[i])
            continue;
        ll res = 1;
        for(ll j = i * 2; j <= n + 1; j += i)
            is[j] = 1;
    }
    if(n == 1 || n == 2)
    {
        cout << 1 << endl << 1;
        if(n == 2)
            cout << " 1";
        return 0;
    }
    cout << 2 << endl;
    for(int i = 2; i <= n + 1; i++)
    {
        if(!is[i])
            cout << 1 << " ";
        else
            cout << 2 << " ";
    }
}