//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo n,t;
string s;
llo it[100001];
/*set<vector<llo>> solve(llo l,llo r){
	if(l==r){
		set<vector<llo>> kc;
		kc.insert({0});
		return kc;
	}
	else{
		set<vector<llo>> ac;
		for(llo mid=l;mid<r;mid++){
			set<vector<llo>> kk=solve(l,mid);
			set<vector<llo>> mm=solve(mid+1,r);
			for(llo j=0;j<kk.size();j++){
				for(llo ii=0;ii<kk[j].size();ii++){
					kk[j][ii]=-kk[j][ii];
				}
			}
			for(auto j:kk){
				for(auto k:mm){
					vector<llo> bc;
					for(auto ii:j){
						bc.pb(1-ii);
					}
					for(auto ii:k){
						bc.pb(ii);
					}
					ac.insert(bc);
				}
			}
		}
		return ac;
	}
}*/
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//solve(0,5-1);
	cin>>n>>t;
	cin>>s;
	for(llo i=0;i<n;i++){
		it[i]=s[i]-'a';
	}
	if(n==1){
		if(t==(1LL<<it[0])){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
		return 0;
	}
	llo cur=0;
	for(llo i=0;i<n;i++){
		cur-=(1LL<<it[i]);
	}
	cur+=(2*(1LL<<it[n-1]));
	//cout<<cur<<endl;
	if(t<cur){
		cout<<"No"<<endl;
		return 0;
	}
	vector<llo> tt;
	for(llo j=0;j<n-2;j++){
		tt.pb(2*(1LL<<it[j]));
	}
//	sort(tt.begin(),tt.end());
	llo le=t-cur;
	if(tt.size()>0){
		sort(tt.begin(),tt.end());
		reverse(tt.begin(),tt.end());
		for(auto j:tt){
			if(le>=j){
				le-=j;
			}
		}
	}
	if(le==0){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	/*set<vector<llo>> pp=solve(0,n-1);
	for(auto j:pp){
		for(auto k:j){
			cout<<k<<",";
		}
		cout<<endl;
	}
*/











 
	return 0;
}