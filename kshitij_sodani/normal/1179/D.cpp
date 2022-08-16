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
vector<llo> adj[500001];
llo ans=0;
const llo bl=2;
llo ss[500001];
llo val[500001];
void dfs2(llo no,llo par=-1){
	ss[no]=1;
	for(auto j:adj[no]){
		if(j!=par){
			dfs2(j,no);
			ss[no]+=ss[j];
		}
	}
}
/*void dfs(llo no,llo par=-1,llo co=0){
	ans=min(ans,co+(ss[no]*(ss[no]-1)));
	//llo kk=ss[no];
	//cout<<no<<":"<<co<<endl;
	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,no,co+(ss[no]-ss[j])*(ss[no]-ss[j]-1));
		}
	}
}*/
void dfs3(llo no,llo par=-1){
	vector<pair<llo,llo>> tt;
	val[no]=(ss[no]*(ss[no]-1));
	for(auto j:adj[no]){
		if(j!=par){
			dfs3(j,no);
			tt.pb({ss[j],val[j]});
			//tt.pb({val[j],ss[j]});
		}
	}
	sort(tt.begin(),tt.end());
	vector<pair<llo,llo>> ee;
	llo ind=0;
	//set<int> hh;
	while(ind<tt.size()){
		llo ind2=ind;
		while(ind<tt.size()){
			if(tt[ind].a==tt[ind2].a){
				ind++;
			}
			else{
				break;
			}
		}
		if(ind>ind2+1){
			ans=min(ans,tt[ind2].b+tt[ind2+1].b+(n-(tt[ind2].a+tt[ind2+1].a))*(n-(tt[ind2].a+tt[ind2+1].a)-1));
		}
	/*	if(hh.find(tt[ind2].a)!=hh.end()){
			while(true){
				continue;
			}
		}
		hh.insert(tt[ind2].a);*/
		ee.pb({tt[ind2].b,tt[ind2].a});
	}

	for(llo j=0;j<tt.size();j++){
			val[no]=min(val[no],tt[j].b+(ss[no]-tt[j].a)*(ss[no]-tt[j].a-1));
		}

		tt=ee;
		//assert(tt.size()<=800);
		/*if(tt.size()>800){
			while(true){
				continue;
			}
		}*/
	/*	for(auto j:ee){
			cout<<j.a<<":"<<j.b<<endl;
		}
		cout<<endl;*/
	//if(adj[no].size()<bl){
		for(llo i=0;i<tt.size();i++){
			for(llo j=i+1;j<tt.size();j++){
				ans=min(ans,tt[i].a+tt[j].a+(n-tt[i].b-tt[j].b)*(n-tt[i].b-tt[j].b-1));
			}
		}
		for(auto j:tt){
			ans=min(ans,j.a+(n-j.b)*(n-j.b-1));
		}
	//}
	
	
//	cout<<no<<":"<<val[j]<<endl;
	//if(tt.size()==0){
		
	//}
	//cout<<no<<":"<<val[j]<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(llo i=0;i<n-1;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	if(n==2){
		cout<<2<<endl;
		return 0;
	}
	ans=n*(n-1);
	llo cur=-1;
	for(llo i=0;i<n;i++){
		/*if(adj[i].size()>=bl){
			dfs2(i);
			dfs(i);
		}*/
		if(adj[i].size()>1){
			cur=i;
		}
	}
	//cout<<cur<<":"<<endl;
	dfs2(cur);
	dfs3(cur);
	ans=n*(n-1)-ans;
	ans+=n*(n-1);
	ans/=2;
	cout<<ans<<endl;





 
	return 0;
}