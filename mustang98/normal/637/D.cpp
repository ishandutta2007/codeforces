#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll n,s,d,f;
ll m[200001];
vector <pair<ll, ll> > dom;//domains

int main()
{
    cin>>n>>f>>s>>d;
    for (ll i=0;i<n;i++) cin>>m[i];
    sort(m,m+n);
    dom.push_back(make_pair(0,m[0] - 1));//1  
    for (ll i = 1;i < n;i++)
        if (m[i] - m[i-1] >= s + 2) dom.push_back(make_pair(m[i-1] + 1,m[i] - 1));//    ,
                                                                                      //  
    dom.push_back(make_pair(m[n-1]+1,f));// 
    if (dom[dom.size()-1].second - dom[dom.size()-1].first<s) dom[dom.size()-1].first=f;//    
    //,     
    //for (ll i=0;i<dom.size();i++) cout<<dom[i].first<<' '<<dom[i].second<<endl;
    if (dom[0].second-dom[0].first<s) {cout<<"IMPOSSIBLE"; return 0;}//   
    for (ll i=1;i<dom.size();i++)
        if (dom[i].first-dom[i-1].second>d) {cout<<"IMPOSSIBLE"; return 0;}//  

    cout<<"RUN "<<dom[0].second-dom[0].first<<endl;
    for(ll i=1;i<dom.size();i++)
    {
        cout<<"JUMP "<<dom[i].first-dom[i-1].second<<endl;
        if (dom[i].first!=f) cout<<"RUN "<<dom[i].second-dom[i].first<<endl;
    }
    return 0;
}