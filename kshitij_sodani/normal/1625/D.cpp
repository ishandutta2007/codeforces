//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo it[300001];
llo n,k;
pair<llo,pair<llo,llo>> ma;
void solve2(vector<int> &aa,vector<int> &bb,llo ind=29,llo su=0){
	/*if(ind<=10){
		for(auto j:aa){
			cout<<j<<":";
		}
		cout<<endl;
		for(auto j:bb){
			cout<<j<<":";
		}
		cout<<endl;
		cout<<ind<<endl;
		
	}*/
	if(aa.size()==0 or bb.size()==0){
		return;
	}
	if(ind==-1){
		if(su>ma.a){
			ma={su,{aa[0],bb[0]}};
		}
		return;
	}
	vector<int> cc;
	vector<int> dd;
	vector<int> ee;
	vector<int> ff;
	for(auto j:aa){
		if((1LL<<ind)&it[j]){
			cc.pb(j);
		}
		else{
			dd.pb(j);
		}
	}
	for(auto j:bb){
		if((1LL<<ind)&it[j]){
			ee.pb(j);
		}
		else{
			ff.pb(j);
		}
	}
	if((cc.size()>0 and ff.size()>0) or (dd.size()>0 and ee.size()>0)){
		solve2(cc,ff,ind-1,su+(1LL<<ind));
		solve2(dd,ee,ind-1,su+(1LL<<ind));
	}
	else{
		solve2(aa,bb,ind-1,su);
	}

}
vector<int> solve(vector<int> &ss,llo ind=29){
	if(ind<0){
		return ss;
	}
	if(ss.size()==0){
		return {};
	}
	if((1LL<<ind)&k){
		ma={-1,{-1,-1}};

		vector<int> aa;
		vector<int> bb;
		for(auto j:ss){
			if((1LL<<ind)&it[j]){
				aa.pb(j);
			}
			else{
				bb.pb(j);
			}
		}
		solve2(aa,bb,29);
	/*	for(auto j:aa){
			cout<<j<<",";
		}
		cout<<endl;
		for(auto j:bb){
			cout<<j<<",";
		}
		cout<<endl;
		cout<<ma.a<<endl;*/
		if(ma.a<k){
			return {ss[0]};
		}
		vector<int> xx;
		xx.pb(ma.b.a);
		xx.pb(ma.b.b);
		return xx;

		//check if 2 is possible
	}
	else{
		vector<int> aa;
		vector<int> bb;
		for(auto j:ss){
			if((1LL<<ind)&it[j]){
				aa.pb(j);
			}
			else{
				bb.pb(j);
			}
		}
		vector<int> ans=solve(aa,ind-1);
		vector<int> ans2=solve(bb,ind-1);
		for(auto j:ans2){
			ans.pb(j);
		}
		return ans;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>k;
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	vector<int> ss;
	for(llo i=0;i<n;i++){
		ss.pb(i);
	}
	vector<int> ans=solve(ss);
	if(ans.size()<=1){
		cout<<-1<<endl;
		return 0;
	}
	cout<<ans.size()<<endl;
	for(auto j:ans){
		cout<<j+1<<" ";
	}
	cout<<endl;


 
	return 0;
}