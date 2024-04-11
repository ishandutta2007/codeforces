#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>P;

int n,d;
int sum[100001];
vector<P>v;
signed main(){
    cin>>n>>d;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back(P(a,b));
    }

    sort(v.begin(),v.end());
    vector<int>money;

    for(int i=0;i<n;i++){
        money.push_back(v[i].first);
        sum[i+1]=v[i].second+sum[i];
    }

    int ans=0;

    for(int i=0;i<n;i++){
        int l=lower_bound(money.begin(),money.end(),v[i].first+d)-money.begin();
        ans=max(ans,sum[l]-sum[i]);
    }

    cout<<ans<<endl;
}