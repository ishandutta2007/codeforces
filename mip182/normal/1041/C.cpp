#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,m,d;
    cin>>n>>m>>d;
    vector <ll> a(n);
    vector <int> ans(n);
    int anss=0;
    set <pair <int,int> > s; 
    for (int i=0;i<n;i++)
    cin>>a[i],s.insert({a[i],i});
    while (!s.empty())
    {
          anss++;
          int f=0;
          while (f<m)
          {
                auto to=s.upper_bound({f,1e9+100});
                if (to==s.end())
                break;
           //     cout<<(*to).first<<'\n';
         //  cout<<#f<<'\n';
                f=(*to).first+d;
                ans[(*to).second]=anss;
                s.erase(to);
          }
    }
    cout<<anss<<'\n';
    for (int i=0;i<n;i++)
    cout<<ans[i]<<" ";
    
}