#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define find finddd
const int maxn = 5e6 + 20;
ll p[maxn];
ll find(ll v)
{
    if(v >= 5e6)
        return maxn - 1;
    return (p[v] == v ? v : p[v] = find(p[v]));
}
ll last = -1;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i <= 3e6; i++)
        s += 'a' , p[i] = i;
    for(int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        int k;
        cin >> k;
        for(int i = 0; i < k; i++)
        {
            int x;
            cin >> x;
            x--;
            last = max(last , x + (ll)t.size());
            for(ll j = x; j < (ll)t.size() + x; )
            {
                s[j] = t[j - x];
                p[j] = find(j + 1);
                j = p[j];
            }
        }
    }
    for(int i = 0; i < last; i++)
        cout << s[i];
    cout << endl;
}