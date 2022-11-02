#include<bits/stdc++.h>
using namespace std;
int n,i;
bool ss = false;
vector<int> v;
map<int,int> mp;
pair<int,int> eq;

int main()
{
    cin>>n;
    v.push_back(0);
    v.push_back(0);
    for(i=2; i<=n; i++)
    {
        cout<<"XOR 1"<<' '<<i<<"\n";
        fflush(stdout);
        int a;
        cin>>a;
        v.push_back(a);
        if(!mp.count(a))
            mp.insert({a,i});
        else
            eq = {i, mp[a]}, ss = true;
    }
    if(mp.count(0)!=0)
    {
        cout<<"OR 1 "<<mp[0]<<"\n";
        fflush(stdout);
        cin>>v[0];
        cout<<"! ";
        for(i=1; i<=n; i++)
        {
            int cur = v[0] ^ v[i];
            cout<<cur<<' ';
        }
        cout<<"\n";
        fflush(stdout);
    }
    else if(ss)
    {
        cout<<"OR "<<eq.first<<' '<<eq.second<<"\n";
        fflush(stdout);
        int a;
        cin>>a;
        v[0] = v[eq.first] ^ a;
        cout<<"! ";
        for(i=1; i<=n; i++)
        {
            int cur = v[0] ^ v[i];
            cout<<cur<<' ';
        }
        cout<<"\n";
        fflush(stdout);
    }
    else
    {

        for(i=2; i<=n; i++)
        {
            if(v[i]==1)
                cout<<"OR 1 "<<i<<"\n";
        }
        int a;
        fflush(stdout);
        cin>>a;
        v[0] = (a/2)*2;
        for(i=2; i<=n; i++)
        {
            if(v[i]==2)
                cout<<"OR 1 "<<i<<"\n";
        }
        fflush(stdout);
        cin>>a;
        v[0] += a%2;
        cout<<"! ";
        for(i=1; i<=n; i++)
        {
            int cur = v[0] ^ v[i];
            cout<<cur<<' ';
        }
        cout<<"\n";
        fflush(stdout);
    }
}