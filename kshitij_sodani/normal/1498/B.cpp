//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'





int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,w;
		cin>>n>>w;
	//	vector<llo> bb;
		multiset<llo> xx;
		for(llo i=0;i<n;i++){
			llo aa;
			cin>>aa;
			//bb.pb(aa);
			xx.insert(aa);
		}
		llo cur=0;
		llo le=w;
		while(xx.size()){
			auto j=xx.upper_bound(le);
			if(j==xx.begin()){
				cur++;
				le=w;
				continue;
			}
			j--;
			//cout<<le<<":"<<endl;
			le-=(*j);
			xx.erase(j);
		}
		cout<<cur+1<<endl;
	
		
		
	}








 
	return 0;
}