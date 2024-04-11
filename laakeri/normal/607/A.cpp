#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int dp[202020];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int, int> > a(n);
    for (int i=0;i<n;i++){
        cin>>a[i].F>>a[i].S;
    }
    sort(a.begin(), a.end());
    int ma=0;
    for (int i=0;i<n;i++){
        pair<int, int> lol={a[i].F-a[i].S, -1};
        int k=lower_bound(a.begin(), a.end(), lol)-a.begin();
        if (k==0){
            dp[i]=1;
        }
        else{
            dp[i]=dp[k-1]+1;
        }
        ma=max(ma, dp[i]);
    }
    cout<<n-ma<<endl;
}