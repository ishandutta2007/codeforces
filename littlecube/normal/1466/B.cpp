#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, note[200010];
        map<int, int> d;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> note[i];
        for (int i = 0; i < n; i++)
            d[note[i]]++;
        for (int i = 0; i < n; i++){
            if(d[note[i]] >= 2){
                d[note[i]]--;
                d[note[i] + 1]++;
            }
        }
        cout << d.size() << '\n';
    }
}