#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main() {
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<int> a(n);
		rep(i,n)cin>>a[i];
		
		map<int,int> mp;
		rep(i,n)mp[a[i]] ++;
		
		int ans = mp.size();
		set<int> s;
		
		for(int i=n-1;i>=0;i--){
			if(i!=n-1 && a[i+1] < a[i])break;
			mp[a[i]]--;
			if(mp[a[i]]==0){
				mp.erase(a[i]);
				s.erase(a[i]);
			}
			else{
				s.insert(a[i]);
			}
			if(s.size()==0){
				ans = min(ans,(int)mp.size());
			}
			
		}
		cout<<ans<<endl;
		
		
	}
	
    return 0;
}