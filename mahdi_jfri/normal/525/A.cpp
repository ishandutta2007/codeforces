#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int key[maxn] , res;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i += 2)
    {
        key[s[i] - 'a']++;
        if(!key[s[i + 1] - 'A'])
            res++;
        else
            key[s[i + 1] - 'A']--;
    }
    cout << res;
}