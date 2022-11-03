#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
pair<int , int> a[maxn];
ll res , _max;
int main()
{
    int n , d;
    cin >> n >> d;
    for(int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a , a + n);
    int fr , bck;
    fr = bck = 0;
    while(fr < n)
    {
        res += a[fr].second;
        while(a[fr].first - a[bck].first >= d && bck <= fr)
        {
            res -= a[bck].second;
            bck++;
        }
        _max = max(res , _max);
        fr++;
    }
    cout << _max;
}