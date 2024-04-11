/** Ithea Myse Valgulious **/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
using pii = pair<int,int>;
int T;

void solve()
{
    int n,i;
    string s;
    cin>>n>>s;
    sort(s.begin(),s.end());
    for(auto it: s)
        cout<<it;
    cout<<endl;
}

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/

    cin>>T;
    while(T--)
        solve();
    return 0;
}