#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
typedef long long ll;

const int max_n = 1000005;
int m[max_n];

int main()
{
    int n, a, b;
    string str;
    set<char> s;
    s.insert('A');
    s.insert('E');
    s.insert('Y');
    s.insert('U');
    s.insert('I');
    s.insert('O');
    cin>>str;
    int ans = -10;
    for(int i = 0; i <= str.size(); i++)
    {
        if ( i < str.size() && s.count(str[i] == 0)) continue;
        int k = i - 1;
        while (true)
        {
            if (s.count(str[k]) || k == -1)
            {
                ans = max(ans, i - k);
                break;
            }
            k--;
        }
    }
    cout<<ans;
    //cin >> n;
    //cin >> a >> b;
    /*for(int i = 0; i < n; i++)
    {
        cin>>m[i];
    }*/
    return 0;
}