#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define stoi ssstoi
const int maxn = 1e3 + 20;
string a[maxn];
int n , m , k , ans , c;
string tob(int c)
{
    string s;
    while(c)
    {
        s = (c % 2 == 0?"0":"1") + s;
        c /= 2;
    }
    while(s.size() < 20)
        s = "0" + s;
    return s;
}
bool check(string s)
{
    int t = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] != a[m][i])
            t++;
    }
    return t <= k;
}
int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i <= m; i++)
    {
        cin >> c;
        a[i] = tob(c);
    }
    for(int i = 0; i < m; i++)
    {
        if(check(a[i]))
            ans++;
    }
    cout << ans;
}