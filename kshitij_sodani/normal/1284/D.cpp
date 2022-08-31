//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo n;
llo aa[100001];
llo bb[100001];
llo cc[100001];
llo dd[100001];


llo st=1;
/*#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ord tree<llo,null_type,less<llo>,rb_tree_tag,tree_order_statistics_node_update>*/
set<llo> xx;
map<llo,llo> yy;
void solve(){
	vector<pair<llo,llo>> ss;
	for(llo i=0;i<n;i++){
		ss.pb({aa[i],-(i+1)});
		ss.pb({bb[i],(i+1)});
	}
	sort(ss.begin(),ss.end());
	set<llo> tt;
	//ord tt;
/*	for(llo i=0;i<=500000;i++){
		tree[i]=0;
	}*/
	set<llo> le;
	for(llo i=1;i<=xx.size();i++){
		le.insert(i);
	}
	for(auto j:ss){
		if(j.b>0){
			vector<llo> kk;
			auto jj=le.lower_bound(yy[cc[(j.b)-1]]);
			while(jj!=le.end()){
				if((*jj)>yy[dd[(j.b)-1]]){
					break;
				}
				else{
					kk.pb(*jj);
					jj++;
				}
			}
			for(auto j:kk){
				le.erase(j);
				tt.insert(j);
			}
		}
		else{

			auto jj=tt.lower_bound(yy[cc[(-j.b)-1]]);
			if(jj!=tt.end()){
				if((*jj)<=yy[dd[-(j.b)-1]]){
					st=0;
				}
			}
		}
	}
//	cout<<endl<<endl<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	
	for(llo i=0;i<n;i++){
		cin>>aa[i]>>bb[i]>>cc[i]>>dd[i];
		xx.insert(aa[i]);
		xx.insert(bb[i]);
		xx.insert(cc[i]);
		xx.insert(dd[i]);
		//ss.pb({aa[i],(i+1)});
		//ss.pb({-bb[i],-(i+1)});
	}
	llo cot=0;
	for(auto j:xx){
		cot++;
		yy[j]=cot;
		//cout<<j<<",,"<<cot<<endl;
	}
	solve();
	for(llo i=0;i<n;i++){
		swap(cc[i],aa[i]);
		swap(dd[i],bb[i]);
	}
	solve();
	if(st){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
/*	set<llo> xx;
	auto jj=xx.lower_bound(0);
	if(jj==xx.end()){
		cout<<11<<endl;
	}
*/





 
	return 0;
}