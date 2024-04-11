#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, ans=0;
string s;
int last[300005];
signed main()
{
    cin>>n>>s;
    s='!'+s+'!';
    for(int i=n; i>=1; i--)
    {
        if(s[i]!=s[i+1])
        {
            last[i]=i;
        }
        else last[i]=last[i+1];
    }
    int ans=0;
    for(int i=1; i<n; i++)
    {
        ans+=n-i;
        if(last[i]!=n)
        {
            if(s[i]==s[i+1])
            {
                ans--;
            }
            else
            {
                ans-=(last[i+1]-i);
            }
        }
    }
    cout<<ans;
}