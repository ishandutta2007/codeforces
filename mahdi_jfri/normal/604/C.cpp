#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define find findd
const int maxn = 1e5 + 20;
int ans = 3;
int main()
{
    int n;
    string s;
    cin >> n >> s;
    for(int i = 1; i < n; i++)
        if(s[i] != s[i - 1])
            ans++;
    if(ans > n)
        ans = n;
    cout << ans;
}