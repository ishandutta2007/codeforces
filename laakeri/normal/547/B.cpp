#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int m[202020];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int, int> > a;
    for (int i=0;i<n;i++){
        int t;
        cin>>t;
        a.push_back({t, i});
    }
    sort(a.rbegin(), a.rend());
    set<int> lol;
    lol.insert(-1);
    lol.insert(n);
    for (int i=0;i<n;i++){
        lol.insert(i);
    }
    for (int i=0;i<n;i++){
        int t=a[i].S;
        lol.erase(t);
        auto it=lol.lower_bound(t);
        int to=*it;
        it--;
        int bo=*it;
        int s=to-bo-1;
        m[s]=max(a[i].F, m[s]);
    }
    for (int i=n-1;i>=1;i--){
        m[i]=max(m[i], m[i+1]);
    }
    for (int i=1;i<=n;i++){
        cout<<m[i]<<" ";
    }
}