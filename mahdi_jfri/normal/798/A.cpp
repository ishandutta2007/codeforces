#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
bool check(string s)
{

}
int main()
{
    string s , s1;
    cin >> s;
    s1 = s;
    reverse(s.begin() , s.end());
    int res = 0;
    if(s == s1)
    {
        if(s.size() % 2)
            cout << "YES";
        else
            cout << "NO";
        return 0;
    }
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == s[s.size() - i - 1])
            continue;
        else
            res++;
    }
    if(res == 2)
    {
        cout << "YES";
        return 0;
    }
    cout << "NO";
}