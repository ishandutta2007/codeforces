#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n;
map<int,int>s;
main(){
	cin>>t;
	while(t--){
		s.clear();
		cin>>n;
		int k=0,ans=0;
		for(int x=1;x<=n;x++){
		    if(x%2==1){
    			int y;
    			cin>>y;
    			while(!s.empty()&&s.rbegin()->first+k>y)
    			s.erase(s.rbegin()->first);
    			k=y-k,s[k-y]++,ans+=s[k];
		    }
		    else
		    {
    			int y;
    			cin>>y;
    			while(!s.empty()&&-s.begin()->first+k>y)
    			s.erase(s.begin()->first);
    			k=y-k,s[y-k]++,ans+=s[-k];
		    }
		}
		cout<<ans<<endl;
	}
}