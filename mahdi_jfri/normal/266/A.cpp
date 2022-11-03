#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e3+20;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]==s[i+1])
        {
            s.erase(i,1);
            i=-1;
        }
    }
    cout<<n-s.size();
}