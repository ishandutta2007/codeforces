#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n+1),cnt(2);
        for(int x=1;x<=n;x++)
        cin>>a[x],cnt[abs(a[x]%2)]++;
        if(cnt[1]%4==0||cnt[1]%4==3||(cnt[1]%4==1&&cnt[0]%2==1))cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
}