#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
string s[maxn];
int res = 1 , n;
int main()
{
    cin >> n;
    cin >> s[0];
    for(int i = 1; i < n; i++)
    {
        cin >> s[i];
        if(s[i][0] == s[i - 1][1])
            res++;
    }
    cout << res;
}