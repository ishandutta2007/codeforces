#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int main()
{
    int c , v0 , v1 , a , l , res = 0;
    cin >> c >> v0 >> v1 >> a >> l;
    c -= l;
    bool f = 0;
    do
    {
        c += l;
        c -= min(v0 , v1);
        v0 += a;
        res++;
    } while(c > 0);
    cout << res;
}