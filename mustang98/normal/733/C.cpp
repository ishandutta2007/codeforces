#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
typedef long long ll;

ll n, k;
vector<ll> a,b;

vector<ll> v[505];
vector<pair<ll, char> > ans;

int main()
{
    ll x;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>x;
        a.push_back(x);
    }
    cin>>k;
    for(int i = 0; i < k; i++)
    {
        cin>>x;
        b.push_back(x);
    }
    ll cur = 0, sum = 0;
    for(int i = 0; i < k; i++)
    {
        while(sum < b[i])
        {
            if (cur == n) {cout<<"NO"; return 0;}
            sum += a[cur];
            v[i].push_back(a[cur]);
            cur++;
        }
        if (sum > b[i]) {cout<<"NO"; return 0;}
        sum = 0;
    }
    if (cur != n) {cout<<"NO"; return 0;}
    //for(int i = 0; i < k; i++) cout<<v[i].size()<<endl;
    for(int i = 0; i < k; i++)
    {
        if (v[i].size() == 1) continue;
        ll minn = 1e9, maxx = -1e9;
        for(int j = 0; j < v[i].size(); j++)
        {
            if(v[i][j] > maxx) maxx = v[i][j];
            if(v[i][j] < minn) minn = v[i][j];
        }
        if (minn == maxx) {cout<<"NO"; return 0;}
    }

    for(int i = 0; i < k; i++)
    {
        if (v[i].size() == 1)
        {
            continue;
        }
        ll maxx = -1e9;
        for(int j = 0; j < v[i].size(); j++)
        {
            if(v[i][j] > maxx)
            {
                maxx = v[i][j];
            }
        }

        ll mi = 0;
        bool l = false, r = false;
        for(int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] != maxx) continue;
            if (j > 0 && v[i][j - 1] != maxx)
            {
                mi = j;
                l = true;
                break;
            }
            if (j < v[i].size() - 1 && v[i][j + 1] != maxx)
            {
                mi = j;
                r = true;
                break;
            }
        }

        int mi1 = mi;
        if (l == true)
        {
            //cout<<mi<<endl;
            for(int j = 0; j < mi1; j++)
            {
                ans.push_back(make_pair(mi + i, 'L'));
                mi--;
            }
            for(int j = mi1 + 1; j < v[i].size(); j++)
            {
                ans.push_back(make_pair(mi + i, 'R'));
            }
        }
        else
        {
            for(int j = mi + 1; j < v[i].size(); j++)
            {
                ans.push_back(make_pair(mi + i, 'R'));
            }
            for(int j = 0; j < mi1; j++)
            {
                ans.push_back(make_pair(mi + i, 'L'));
                mi--;
            }
        }
    }
    cout<<"YES\n";
    for(int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i].F + 1<<' '<<ans[i].S << "\n";
    }
    return 0;
}