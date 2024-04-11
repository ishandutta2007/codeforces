
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 

int it[300001];
int ans[300001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<pair<int,int>> aa;
		set<int> ss;
		for(int i=0;i<n;i++){
			ans[i+1]=-1;
			ss.insert(i+1);
		}
		for(int i=0;i<n;i++){
			cin>>it[i];
			aa.pb({it[i],i});
		}
		sort(aa.begin(),aa.end());
		int ind=0;
		while(ind<n){
			int ind2=ind;
			vector<int> bb;
			bb.pb(aa[ind].b);
			for(int i=ind+1;i<n;i++){
				if(aa[i].a!=aa[ind].a){
					break;
				}
				ind2++;
				bb.pb(aa[ind2].b);
			}
			int ma=bb[0];
			ma=max(ma,n-bb.back()-1);
			/*for(auto j:bb){
				cout<<j<<":";
			}
			cout<<endl;*/
			if(bb.size()>1){
				for(int i=0;i<bb.size()-1;i++){
					ma=max(ma,bb[i+1]-bb[i]-1);
				}
			}

			ma+=1;
			//cout<<ma<<endl;
			auto j=ss.lower_bound(ma);
			vector<int> kk;
			while(j!=ss.end()){
				ans[*j]=aa[ind].a;
				kk.pb(*j);
				j++;
				
			}
			for(auto j:kk){
				ss.erase(j);
			}
			ind=ind2+1;
		}
		for(int i=1;i<=n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;





	}
	









	return 0;
}