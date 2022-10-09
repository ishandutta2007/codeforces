#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define e1 first
#define e2 second
typedef long long int ll;
typedef pair <int, int> BONG;
typedef unsigned int ui;
const ll inf = 1e18;
int n, k;
#define maxn 30
ll wyn =inf;
int t1[30], t2[30];
int main()
{
    string s, t;
    int wyn = 0;
    cin >> s;
    cin >> t;
    for (int i=0; i<s.length(); ++i) t1[s[i] - 'a']++;
    for (int i=0; i<t.length(); ++i) t2[t[i] - 'a']++;
    for (int i=0; i<26; ++i) 
    {
        if (t2[i] != 0 && t1[i] == 0)
        {
            puts("-1");
            return 0;
        } 
        wyn += min(t1[i], t2[i]);
    }
    if (wyn == 0) puts("-1");
    else cout << wyn;
}