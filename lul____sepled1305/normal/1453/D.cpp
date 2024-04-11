#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll cur = 2;
    vector<ll> v;
    for(int i=1;;i++)
    {
        v.push_back(cur);
        cur*=2;
        cur+=2;
        if(cur>1e18)
            break;
    }

    int t;
    cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        if(n%2 == 1)
        {
            cout<<"-1\n";
            continue;
        }
        else
        {
            int sum = 0;
            vector<int> ans;
            while(n>0)
            {
                for(i=v.size()-1;i>=0;i--)
                {
                    if(v[i] <= n)
                    {
                        ans.push_back(i);
                        n-=v[i];
                        sum+=(i+1);
                        break;
                    }
                }
            }
            if(sum > 2000)
            {
                cout<<"-1\n";
                continue;
            }
            else
            {
                cout<<sum<<endl;
                while(!ans.empty())
                {
                    int kk = ans.back();
                    ans.pop_back();
                    cout<<"1 ";
                    while(kk > 0)
                    {
                        cout<<"0 ";
                        kk--;
                    }
                }
                cout<<endl;
            }
        }
    }
}