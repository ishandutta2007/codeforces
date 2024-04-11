//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int it[2001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> ss;
		for(int i=0;i<2*n;i++){
			cin>>it[i];
			ss.pb(it[i]);
		}
		sort(ss.begin(),ss.end());
		int st=0;
		for(int i=0;i<2*n-1;i++){
			multiset<int> aa;
			for(auto j:ss){
				aa.insert(j);
			}
			int xx=ss.back()+ss[i];
			vector<pair<int,int>> ans;
		//	cout<<i<<",,"<<endl;

			while(aa.size()){
				auto j=aa.end();
				j--;
				int ac=*j;
			//	cout<<ac<<endl;
				aa.erase(j);
		
				if(aa.find(xx-ac)==aa.end()){
					break;
				}
				auto jj=aa.find(xx-ac);
				int cc=*jj;
				aa.erase(jj);
				ans.pb({ac,cc});
				//cout<<ac<<","<<cc<<endl;
				xx=ac;
			}
			if(ans.size()<n){
				continue;
			}
			st=1;
			cout<<"YES"<<endl;
			cout<<ss.back()+ss[i]<<endl;
			for(auto j:ans){
				cout<<j.a<<" "<<j.b<<endl;
			}
			break;
		}
		if(st==0){
			cout<<"NO"<<endl;
		}



	}





	
 
	return 0;
}