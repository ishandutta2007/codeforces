//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int it[300001];
int le[300001];
int re[300001];
//int vis[300001];
int ma[300001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<=n;i++){
			ma[i]=0;
			//tt[i].clear();
			//pre[i].clear();
		///	cot[i]=-1;
		}
		for(int i=0;i<n;i++){
			cin>>it[i];
		//	tt[it[i]].insert(i);
		}
		vector<pair<int,int>> ss;
		for(int i=0;i<n;i++){
			while(ss.size()){
				if(ss.back().a>=it[i]){
					ss.pop_back();
				}
				else{
					break;
				}
			}
			le[i]=0;
			if(ss.size()){
				le[i]=ss.back().b+1;
			}
			ss.pb({it[i],i});
		}
		ss.clear();
		for(int i=n-1;i>=0;i--){
			while(ss.size()){
				if(ss.back().a>=it[i]){
					ss.pop_back();
				}
				else{
					break;
				}
			}
			re[i]=n-1;
			if(ss.size()){
				re[i]=ss.back().b-1;
			}
			ss.pb({it[i],i});
		}
		
	//	int ma=n;
		/*vector<int> aa;
		for(int i=0;i<n;i++){
			aa.pb(i+1);
		}*/
		/*set<int> cur;
		for(int i=0;i<n;i++){
			cur.insert(i+1);
		}
*/
		for(int i=0;i<n;i++){
			/*int j=*tt[it[i]].lower_bound(le[i]);
			auto jj=tt[it[i]].upper_bound(re[i]);
			jj--;
			int k=*jj;
*/	
			/*if(true){
				auto j=cur.upper_bound(n-it[i]+1);
				vector<int> kk;
				while(j!=cur.end()){
					if(*j<=re[i]-le[i]+1){
					//	cout<<(*j)<<":"<<i<<":"<<re[i]-le[i]+1<<endl;
						kk.pb(*j);
						j++;
					}
					else{
						break;
					}
				}
				for(auto jj:kk){
					cur.erase(jj);
				}
			}*/
			ma[it[i]]=max(ma[it[i]],re[i]-le[i]+1);
		//	cout<<re[i]-le[i]+1<<endl;
			
		/*	if(j<k){
				while(bb.size()){
					if(bb.back()<k-j+1){
						cout<<bb.back()<<endl;
						vis[bb.back()]=1;
						bb.pop_back();
					}
					else{
						break;
					}
				}
			}*/
			
			
			/*cout<<le[i]<<","<<re[i]<<endl;
			if(j==i){
				pre[it[i]].pb(re[i]-le[i]+1);
				//cot[it[i]]=k;
			}*/

			/*if(le[i]<i and re[i]>i){
				int cur=re[i]-le[i];
				while(aa.size()){
					if(aa.back()<=cur){
						vis[aa.back()]=1;
						aa.pop_back();
					}
					else{
						break;
					}
				}
			}
			if(true){
				int cur=re[i]-le[i]+1;
				
			}*/
		}
		int mi=n;
		/*for(int i=1;i<=n;i++){
			cout<<ma[i]<<",";
		}
		cout<<endl;
		for(auto j:cur){
			cout<<j<<",";
		}
		cout<<endl;*/
		string ans="";
		for(int i=1;i<=n;i++){

			mi=min(mi,ma[i]);
			/*int st=1;
			for(int j=1;j<=n-i+1;j++){
				//1-ma[j]
				if(i<n-ma[j]+1){
					st=0;
				}
			}
*/
			/*if(cur.find(i)==cur.end()){
				ans+="0";
			}
			else{*/
			//	cout<<st;
				//continue;
				if(n-mi+1<=i){
					ans+="1";
				}
				else{
					ans+="0";
				}
		//	}


		}
		for(int i=n-1;i>=0;i--){
			cout<<ans[i];
		}
		cout<<endl;
	/*	pair<int,int> ans={0,n-1};
		for(int i=1;i<=n;i++){
			if(pre[i].size()==0){
				ans={-1,-1};
			}
			else if(pre[i].size()==1){
				ans.b=min(ans.b,pre[i][0]);//={0,pre[i][0]};
			}
			else{
				sort(pre[i].begin(),pre[i].end());
				ans.a=max(ans.a,pre[i][pre[i].size()-2]+1);
				ans.b=min(ans.b,pre[i].back());
			}

		}
		for(int i=0;i<n;i++){
			if(i>=ans.a and i<=ans.b){
				if(vis[i]){
					cout<<0;
				}
				else{
					cout<<1;
				}
			}
			else{
				cout<<0;
			}
		}
		cout<<endl;*/






	}















 
	return 0;
}