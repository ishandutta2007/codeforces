#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
ll k , t[maxn];
bool c(int a , int b)
{
    int x = (a ^ b) , res = 0;
    for(int i = 0; i <= 14; i++)
        if((x >> i) & 1)
            res++;
    return res == k;
}
int main()
{
    int n;
    cin >> n >> k;
    ll res = 0;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        t[x]++;
    }
    for(int i = 0; i <= 1e4; i++)
    {
        if(!t[i])
            continue;
        for(int j = i; j <= 1e4; j++)
        {
            if(!t[i] || !c(i , j))
                continue;
            if(i != j)
                res += t[i] * t[j];
            else
                res += t[i] * (t[i] - 1) / 2;
        }
    }
    cout << res;
}