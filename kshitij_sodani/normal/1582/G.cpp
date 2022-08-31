//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int n;
int aa[1000001];
int bb[1000001];
vector<pair<int,int>> pre[1000001];
vector<pair<int,int>> pre2[1000001];
bool vis[1000001];
vector<int> pre3[1000001];
vector<int> pre4[1000001];
int val[1000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=2;i<=1000000;i++){
		if(vis[i]==0){
			for(int j=i;j<=1e6;j+=i){
				vis[j]=1;
				/*int le=j;
				int cur=0;
				while(le%i==0){
					cur++;
					le/=i;
				}*/
				pre[j].pb({i,1});
			}
			llo cur=i;
			llo ii=i;
			while(cur*ii<=1e6){
				cur*=ii;
				for(int j=cur;j<=1e6;j+=cur){
					pre[j][pre[j].size()-1].b+=1;
				}
			}
		}
	}

	for(int i=0;i<n;i++){
		val[i]=n;
		cin>>aa[i];

	}
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='*'){
			bb[i]=1;
		}
		else{
			bb[i]=-1;
		}
		for(auto j:pre[aa[i]]){
			if(pre2[j.a].size()==0){
				pre2[j.a].pb({-1,0});
			}
			pre2[j.a].pb({i,pre2[j.a].back().b+j.b*bb[i]});
		}
	}
	for(int i=2;i<=1000000;i++){
		if(pre2[i].size()){
			vector<pair<int,int>> ss;
			/*for(auto j:pre2[i]){
				cout<<j.a<<":"<<j.b<<endl;
			}*/
			//
			for(int j=pre2[i].size()-1;j>=0;j--){
				while(ss.size()){
					if(ss.back().b>=pre2[i][j].b){
						ss.pop_back();
					}
					else{
						break;
					}
				}
				if(ss.size()){
					//range pre2[i][j].b+1 to pre2[i][j+1].b
					//min with ss.back().b;
					if(pre2[i][j+1].a-pre2[i][j].a<=4){
						for(int k=pre2[i][j].a+1;k<=pre2[i][j+1].a;k++){
							val[k]=min(val[k],ss.back().a);

						}

					}
					else{
						pre3[pre2[i][j].a+1].pb(ss.back().a);
						pre4[pre2[i][j+1].a].pb(ss.back().a);
					}
				}

				ss.pb(pre2[i][j]);
			}
		}
	}

	multiset<int> cur;
	llo ans=0;
	for(int i=0;i<n;i++){
		for(auto j:pre3[i]){
			cur.insert(j);
		}
		int cot=val[i];
		if(cur.size()){
			cot=min(cot,*(cur.begin()));
		}
		//cout<<cot<<"::"<<endl;
		ans+=cot-i;
		for(auto j:pre4[i]){
			auto jj=cur.find(j);
			cur.erase(jj);
		}
	}
	cout<<ans<<endl;
 
 	
 

 
	return 0;
}