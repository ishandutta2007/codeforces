#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int main() {
    int T; cin>>T;
    while(T--) {
        int n,m; cin>>n>>m;
        int a[n*m];
        vector<pii> v;
        for(int i=0;i<n*m;i++)
        	cin>>a[i], v.push_back({a[i],-i});
        //Assign seat
        sort(v.begin(),v.end());
        int s[n*m];
        int pointer = 0;
        for(auto it: v) {
        	s[-it.second] = pointer;
        	pointer++;
        }
        int ans = 0;
        for(int i=0;i<m;i++) {
        	//cout<<i<<' '<<s[i]<<endl;
        	for(int j=0;j<i;j++) {
        		if(s[j] < s[i])
        			ans++;
        	}
        }
        cout<<ans<<endl;
    }
    return 0;
}