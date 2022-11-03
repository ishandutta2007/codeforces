#include<bits/stdc++.h>
using namespace std;
string s[3];
int main()
{
    cin >> s[0] >> s[1] >> s[2];
    s[0]+=s[1];
    sort(s[0].begin(),s[0].end());
    sort(s[2].begin(),s[2].end());
    if(s[0] == s[2])
        cout << "YES";
    else
        cout << "NO";
}