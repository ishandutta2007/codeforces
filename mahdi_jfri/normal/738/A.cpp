#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
string s , s1;
int main()
{
    int n;
    cin >> n;
    cin >> s;
    if(n < 3)
    {
        cout << s;
        return 0;
    }
    for(int i = 0; i < s.size(); i++)
    {
        if(i + 2 < n && s[i] == 'o' && s[i + 1] == 'g' && s[i + 2] == 'o')
        {
            i += 3;
            s1 += "***";
            while(i + 1 < n && s[i] == 'g' && s[i + 1] == 'o')
                i += 2;
            i--;
        }
        else
            s1 += s[i];
    }
    cout << s1;
}