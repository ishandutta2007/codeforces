//For 1279F
#include<bits/stdc++.h>
using namespace std;

pair<int,int> calc(int a[], int cost, int n, int l) {
    pair<int,int> dp[n+1];
    for(int i=0;i<=n;i++)
        dp[i] = {1e9,1e9};
    dp[0] = {0,0};
    for(int i=0;i<n;i++) {
        if(dp[i+1] > make_pair(dp[i].first + a[i], dp[i].second))
            dp[i+1] = {dp[i].first + a[i], dp[i].second};
        if (dp[min(n, i + l)] > make_pair(dp[i].first + cost, dp[i].second + 1)) {
			dp[min(n, i + l)] = {dp[i].first + cost, dp[i].second + 1};
		}
    }
    return dp[n];
}

int main() {
    int n,k,l;
    cin>>n>>k>>l;
    string s;
    cin>>s;
    int a[n];
    //Step 1: convert string to array with 1 for uppercased 0 for lowercased
    for(int i=0;i<n;i++)
        if(s[i]-'a'>=0)
            a[i] = 0;
        else
            a[i] = 1;
    //Step 2: assume the answer is changing to lowercased. Use alien trick to calculate
    int mi = 0, ma = n+1;
    while(mi < ma) {
        int md = mi + ma >> 1;
        if(md == mi) {
            if(calc(a,ma,n,l).second <= k)
                mi = ma;
            else
                ma = mi;
        }
        else {
            if(calc(a,md,n,l).second <= k)
                ma = md;
            else
                mi = md;
        }
    }
    pair<int,int> cur = calc(a,mi,n,l);
    int ans = max(cur.first - mi*k,0);
    //Step 3: switch 1 and 0 and try again
    for(int i=0;i<n;i++)
        if(s[i]-'a'>=0)
            a[i] = 1;
        else
            a[i] = 0;
    mi = 0, ma = n+1;
    while(mi < ma) {
        int md = mi + ma >> 1;
        if(md == mi) {
            if(calc(a,ma,n,l).second <= k)
                mi = ma;
            else
                ma = mi;
        }
        else {
            if(calc(a,md,n,l).second <= k)
                ma = md;
            else
                mi = md;
        }
    }
    cur = calc(a,mi,n,l);
    ans = min(max(cur.first - mi*k,0),ans);
    cout<<ans;
    return 0;
}