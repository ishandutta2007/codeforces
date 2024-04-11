#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<ll> t(n);
    for (int i=0;i<n;i++){
        cin>>t[i];
    }
    sort(t.begin(), t.end());
    ll s=0;
    int v=0;
    for (int i=0;i<n;i++){
        if (s<=t[i]){
            s+=t[i];
            v++;
        }
    }
    cout<<v<<endl;
}