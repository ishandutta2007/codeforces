//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int aa[101];
vector<int> adj[2000001];
int n;
int cal(int no){
	if(no==1){
		return 1;
	}
	else{
		return 1+3*cal(no/2);
	}
}
int dp[101];
mt19937 rng;
vector<int> tt;
int ss[2000001];
int cot;
int cop=0;
int st[200001];
int endd[200001];
//vector<pair<pair<int,int>,int>> pp;
void dfs(int no,int par=-1){
	ss[no]=1;
	st[no]=cop;
	cop++;
	for(auto j:adj[no]){
		if(j!=par){

			dfs(j,no);
			ss[no]+=ss[j];
		}
	}
	adj[no].clear();
	if(ss[no]==aa[cot-2] or ss[no]==aa[cot-1]){
		tt.pb(no);
	}
	endd[no]=cop-1;
	//pp.pb({no,{st[no],endd[no]}});
}
bool solve(vector<pair<int,int>> &ed,int nn){
	//assert(((int)ed.size())+1==aa[nn]);
	if(nn==1 or nn==2 or nn==3){
		return true;
	}
	cot=nn;
	for(int i=0;i<ed.size();i++){
		adj[ed[i].a].pb(ed[i].b);
		adj[ed[i].b].pb(ed[i].a);
	}
	cop=0;
	//
	//return false;
	tt.clear();
	dfs(ed[0].a);
	/*for(int i=0;i<ed.size();i++){
		adj[ed[i].a].pop_back();
		adj[ed[i].b].pop_back();
	}
*/
	if(tt.size()==0){
		return false;
	}
	if(nn==4){
		return true;
	}
	vector<int> ttt;
	for(auto j:tt){
		ttt.pb(j);
	}

	if(ttt.size()>1){
		if((rng()%2==0)){
			swap(ttt[0],ttt[1]);
		}
		//shuffle(ttt.begin(),ttt.end(),rng);
	}

	//cout<<endl;

	vector<vector<pair<int,int>>> ccc;
	vector<vector<pair<int,int>>> ddd;
		for(auto j:ttt){
			//ind3++;
			//vector<pair<int,int>> aaa;
		//	vector<pair<int,int>> bbb;
			int ind2=-1;
			ccc.pb({});
			ddd.pb({});
			for(auto i:ed){
				ind2++;
				int x=0;
				if(st[i.a]>=st[j] and endd[i.a]<=endd[j]){
					x=1;
				}
				int y=0;
				if(st[i.b]>=st[j] and endd[i.b]<=endd[j]){
					y=1;
				}
				if(x+y==1){
					continue;
				}
				if(x==1 and y==1){
					ccc[ccc.size()-1].pb(i);
				}
				else{
					ddd[ddd.size()-1].pb(i);
				}
			}


			/*if((aaa.size()<bbb.size())){
				ccc.pb(aaa);
				ddd.pb(bbb);
			}
			else{
				ddd.pb(aaa);
				ccc.pb(bbb);
			}*/
		}


	//int ind3=-1;
	for(int j=0;j<ttt.size();j++){
		//vector<pair<int,int>> aaa=ccc[j];
	//	vector<pair<int,int>> bbb=ddd[j];
		if((rng()%2)==1){
			swap(ccc[j],ddd[j]);
		}
		int nnn=nn-2;
		int mmm=nn-1;
		if(((int)(ccc[j].size())+(int)1)==aa[nn-1]){
			nnn=nn-1;
			mmm=nn-2;
		}
		int xx=solve(ccc[j],nnn);
		if(xx==false){
			continue;
		}
		int yy=solve(ddd[j],mmm);
		if(yy){
			return true;
		}
		return false;
	}
	return false;
	

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	vector<pair<int,int>> ed;
	rng=mt19937(chrono::steady_clock::now().time_since_epoch().count());
	for(int i=0;i<n-1;i++){
		int aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		ed.pb({aa,bb});
	/*	adj[aa].pb(bb);
		adj[bb].pb(aa);*/
	}
	aa[0]=1;
	aa[1]=1;
	for(int i=2;i<=30;i++){
		aa[i]=aa[i-1]+aa[i-2];
	}
	int cur=-1;
	int cur3=-1;
	for(int i=1;i<=30;i++){
		if(n==aa[i]){
			cur=i;
			
		}
		/*if(aa[i]<=200000){
				cur3=i;
			}*/
	}
	//cout<<cur3<<endl;
	//cout<<aa[30]<<endl;
	if(cur==-1){
		cout<<"NO"<<endl;
		return 0;
	}

	int st=solve(ed,cur);
	if(st){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	






	/*dp[1]=1;
	
	dp[2]=1;
	dp[3]=1;
	for(int i=4;i<=26;i++){
		dp[i]=aa[i]+2*((((dp[i-1]*4+dp[i-2]*6)/10)+dp[i-2]+dp[i-1])/2);
	}
	for(int i=1;i<=26;i++){
		cout<<dp[i]<<",";
	}
	cout<<endl;
	cout<<dp[26]<<endl;*/
	return 0;
/*	cout<<cal(200000)<<endl;
	
	int ind=0;
	for(int i=0;i<30;i++){
		if(aa[i]<=200000){
			ind=i;

		}
		cout<<aa[i]<<",";
	}
	cout<<endl;

	cout<<ind<<endl;*/
 	
	return 0;
}