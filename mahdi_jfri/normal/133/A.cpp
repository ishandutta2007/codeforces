#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e3+20;
int main()
{
    string s;
    cin>>s;
    if(s.find("H")!=string::npos || s.find("Q")!=string::npos || s.find("9")!=string::npos)
        cout<<"YES";
    else
        cout<<"NO";
}