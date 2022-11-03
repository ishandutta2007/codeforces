#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
string s;
ll n;
map<char,int> mp;
deque<int>dq;
int main()
{
    cin >> n >> s;
    for(int i = 0 ; i < s.size() ; i++)
    {
        if(mp[s[i]] == 0)
        {
            mp[s[i]]++;
            dq.push_back(i);
        }
        if(dq.size() == n)
            break;
    }
    if(dq.size() < n)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for(int i = 0 ; i < dq.size()-1 ; i++)
    {
        string s1=s.substr(dq[i],dq[i+1]-dq[i]);
        cout << s1 << endl;
    }
    string s1 = s.substr(dq[dq.size()-1]);
    cout << s1 << endl;
    return 0;
}