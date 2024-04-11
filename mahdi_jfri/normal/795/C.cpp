#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e6 + 20;
int main()
{
    int n;
    cin >> n;
    n -= 2;
    string s = "1";
    while(n >= 2)
    {
        s += "1";
        n -= 2;
    }
    int i = 0;
    while(n)
    {
        s[i++] = '7';
        n--;
    }
    cout << s;
}