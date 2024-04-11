#include<bits/stdc++.h>
using namespace std;

string s,t;

bool test(int l,int sz)
{
    for(int i=sz;i<t.size();i++)
    {
        if(l<0||s[l]!=t[i])return 0;
        l--;
    }
    return 1;
}
int solve()
{
    cin>>s>>t;

    int sz_s=s.size();
    int sz_t=t.size();

    for(int i=0;i<sz_s;i++)
        for(int d=0;d<sz_t&&i+d<sz_s&&s[i+d]==t[d];d++)
        {
            if(test(i+d-1,d+1))return 1;
        }

    return 0;
}

int main()
{
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