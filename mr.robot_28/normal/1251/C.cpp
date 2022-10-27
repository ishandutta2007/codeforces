#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll i,j,k,n,m;
    cin>>k;
    while(k--)
    {
        string str,t;
        cin>>t;
        ll sz = t.size();
        queue<ll>odd,even;
        for(i = 0;i<sz;i++)
        {
            ll val = t[i]-'0';
            if(val%2)odd.push(val);
            else even.push(val);
        }
        for(i = 0;i<sz;i++)
        {
            if(!odd.empty() && !even.empty())
            {
                if(odd.front()<even.front())
                {
                    str+=(odd.front()+'0');
                    odd.pop();
                }
                else {
                    str += (even.front()+'0');
                    even.pop();
                }
            }
            else if(!odd.empty())
            {
                str+=(odd.front()+'0');
                odd.pop();
            }
            else if(!even.empty())
            {
                str+=(even.front()+'0');
                even.pop();
            }
        }
        cout<<str<<'\n';
    }
    return 0;
}