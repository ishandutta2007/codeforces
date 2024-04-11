#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    int n;

    string s;

    string t;

    cin>>n>>s>>t;

    int j=0;

    for(int i=0;i<n;i++)
        if(s[i]!=t[i])
        {
            j=max(i,j);

            while(j<n&&s[i]==s[j])j++;

            if(j==n)return 0;

            if(s[i]+1==s[j])swap(s[i],s[j]);

            if(s[i]!=t[i])return 0;
        }

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    int t;
    cin>>t;

    while(t)
    {
        t--;

        if(solve())cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}