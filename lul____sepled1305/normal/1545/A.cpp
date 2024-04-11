/**
    Ithea is the best girl.
**/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        int a[n], b[n];
        for(int i=0;i<n;i++) {
            cin>>a[i]; b[i] = a[i];
        }
        sort(b,b+n);
        map<int,int> mp;
        for(int i=0;i<n;i++) {
            mp[a[i]] += ((i%2)*2-1);
            mp[b[i]] -= ((i%2)*2-1);
        }
        bool f = true;
        for(int i=0;i<n;i++) {
            if(mp[a[i]] != 0)
                f = false;
        }

        if(!f)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}