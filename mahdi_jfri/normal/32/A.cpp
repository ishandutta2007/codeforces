// Be name khoda, Lanat be physic
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int a[maxn];
ll res;
int main()
{
    int n , d;
    cin >> n >> d;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if(i == j)
                continue;
            res += abs(a[i] - a[j]) <= d;
        }
    cout << res;
}