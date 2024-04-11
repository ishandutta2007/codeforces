#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
int change[maxn];
int main()
{
    string s;
    cin >> s;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        a--;
        change[a]++;
        change[s.size() - a + 2]--;
    }
    for(int i = 0; i < s.size() / 2; i++)
    {
        change[i] += change[i - 1];
        if(change[i] % 2)
            swap(s[i] , s[s.size() - i - 1]);
    }
    cout << s;
}