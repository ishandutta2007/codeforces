//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'


int it[1001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		for(int i=0;i<n;i++){
			it[i]=s[i]-'0';
		}
		vector<vector<int>> ans;
		for(int i=0;i<n;i++){
			if(it[i]==1){
				int ok=-1;
				for(int j=n-1;j>=i;j--){
					if(it[j]==0){
						ok=j;
						break;
					}
				}
				if(ok!=-1){
					pair<int,int> cur={i,ok};
					vector<int> aa;
					//aa.pb(i);
					vector<int> bb;
					//bb.pb(ok);
					while(cur.a<=cur.b){
						if(aa.size()>bb.size()){
							if(it[cur.b]==0){
								bb.pb(cur.b);
							}
							cur.b--;
							continue;
						}
						if(aa.size()<bb.size()){
							if(it[cur.a]==1){
								aa.pb(cur.a);
							}
							cur.a++;
							continue;
						}
						if(it[cur.a]==1){
							if(it[cur.a]==1){
								aa.pb(cur.a);
							}
							cur.a++;
							continue;
						}
						else if(it[cur.b]==0){
							bb.pb(cur.b);
							cur.b--;
							continue;
						}
						cur.a++;
						cur.b--;
					}
					if(aa.size()>bb.size()){
						aa.pop_back();
					}
					if(bb.size()>aa.size()){
						bb.pop_back();
					}
					for(int j=0;j<aa.size();j++){
						swap(it[aa[j]],it[bb[j]]);
					}
					reverse(bb.begin(),bb.end());
					for(auto j:bb){
						aa.pb(j);
					}
					ans.pb(aa);


				}
			}
		}
		cout<<ans.size()<<endl;
		for(auto j:ans){
			cout<<j.size()<<" ";
			for(auto i:j){
				cout<<i+1<<" ";
			}
			cout<<endl;
		}
	}



 
	return 0;
}