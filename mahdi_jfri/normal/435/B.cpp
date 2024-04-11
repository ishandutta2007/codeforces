#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int maxn = 1e2 + 20;
string s;
int main()
{
    int k;
    cin >> s >> k;
    for(int i = 0; i < s.size(); i++)
    {
        int _max = i;
        for(int j = i + 1; j < s.size() && j - i <= k; j++)
            if(s[j] > s[_max])
                _max = j;
        k -= (_max - i);
        for(int j = _max; j > i; j--)
            swap(s[j] , s[j - 1]);
    }
    cout << s;
}