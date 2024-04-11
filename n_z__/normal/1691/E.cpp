#include<bits/stdc++.h>
using namespace std;
main() {
	int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        array<int,3>v[n+1];
        memset(v,0,sizeof(v));
        for(int x=1;x<=n;x++)
        cin>>v[x][2]>>v[x][0]>>v[x][1];
        sort(v+1,v+1+n);
        int ans=n;
        multiset<int>s[2];
        for(int x=1;x<=n;x++){
            int l=v[x][0],r=v[x][1],c=v[x][2];
            while(!s[0].empty()&&*s[0].begin()<l)s[0].erase(s[0].begin());
            while(!s[1].empty()&&*s[1].begin()<l)s[1].erase(s[1].begin());
            s[c].insert(r);
            if(s[c^1].size()){
                ans--;
                while(s[c^1].size()>1)s[c^1].erase(s[c^1].begin()),ans--;
                if(s[c].size()==2)s[c].erase(s[c].begin());
            }
        }
        cout<<ans<<endl;
    }
}