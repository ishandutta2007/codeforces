/**Chtholly Best Girl**/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,m,i,ans;
vector<int> v[N];
int ori[N];
map<int,int> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        int a;
        cin>>a;
        ori[i] = a;
        v[a].push_back(i);
    }
    for(i=1;i<n;i++)
    {
        if(ori[i]!=ori[i-1])
            ans++;
    }
    cout<<ans<<"\n";
    for(i=0;i<m-1;i++)
    {
        int a,b;
        bool sw = false;
        cin>>a>>b;
        while(mp.count(a))
            a = mp[a];
        while(mp.count(b))
            b = mp[b];
        if(v[b].size() > v[a].size())
            swap(a,b), sw = true;
        for(auto it: v[b])
        {
            if(it!=0 && ori[it-1] == a)
                ans--;
            if(it!=n-1 && ori[it+1] == a)
                ans--;
        }
        for(auto it: v[b])
        {
            v[a].push_back(it);
            ori[it] = a;
        }
        int i;
        if(sw)
            mp.insert({b,a});
        cout<<ans<<"\n";
    }
    return 0;
}