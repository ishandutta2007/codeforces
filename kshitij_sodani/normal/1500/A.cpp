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
int it[200001];
vector<int> pre[3000001];
vector<pair<int,int>> co[7000001];
int co2[7000001];
//int vis[10000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	set<int> ss;
	set<int> xx;
	for(int i=0;i<n;i++){
		cin>>it[i];
		if(ss.size()<3500){
			ss.insert(it[i]);	
			
		}
		pre[it[i]].pb(i+1);
		if(pre[it[i]].size()==2){
			xx.insert(it[i]);
		}
	}
	if(xx.size()>1){
		int bb=*(xx.begin());
		xx.erase(xx.begin());
		int cc=*(xx.begin());
		xx.erase(xx.begin());
		cout<<"YES"<<endl;
		cout<<pre[bb][0]<<" "<<pre[cc][0]<<" "<<pre[bb][1]<<" "<<pre[cc][1]<<endl;
		return 0;
	}
	vector<int> aa;
	for(auto j:ss){
		aa.pb(j);
		//cout<<j<<",";
	}
	//cout<<endl;
	

//	return 0;
	for(int i=0;i<aa.size();i++){
		for(int j=0;j<i;j++){
			co2[aa[i]+aa[j]]=1;
			//cout<
		}
		for(int j=i-1;j>=0;j--){
			/*if(co[aa[i]-aa[j]].size()==0){
				vis[aa[i]-aa[j]]=1;
			}*/
			co[aa[i]-aa[j]].pb({pre[aa[i]][0],pre[aa[j]][0]});
			for(auto jj:co[aa[i]-aa[j]]){
				if(jj.a!=pre[aa[i]][0] and jj.b!=pre[aa[j]][0] and jj.a!=pre[aa[j]][0] and jj.b!=pre[aa[i]][0]){
					//cout<<11<<endl;
					cout<<"YES"<<endl;
					cout<<jj.a<<" "<<co[aa[i]-aa[j]].back().b<<" "<<co[aa[i]-aa[j]].back().a<<" "<<jj.b<<endl;
					return 0;
				}
			}
			
			
			/*if(co[aa[i]-aa[j]].size()>1){
				//cout<<(aa[i]-aa[j])<<",,"<<endl;
				//return 0;
				//cout<<aa[i]<<",,"<<aa[j]<<endl;
				cout<<"YES"<<endl;
				cout<<co[aa[i]-aa[j]][0].a<<" "<<co[aa[i]-aa[j]][1].b<<" "<<co[aa[i]-aa[j]][1].a<<" "<<co[aa[i]-aa[j]][0].b<<endl;
				return 0;
			}*/
		}
	}

	//return 0;
	//return 0;
	for(int i=0;i<aa.size();i++){
		int xx=((int)pre[aa[i]].size());
		if(xx>=4){
			cout<<"YES"<<endl;
			cout<<pre[aa[i]][0]<<" "<<pre[aa[i]][1]<<" "<<pre[aa[i]][2]<<" "<<pre[aa[i]][3]<<endl;
			return 0;
		}
		if(xx>=2){
			if(co2[aa[i]+aa[i]]>0){
				cout<<"YES"<<endl;
				//cout<<aa[i]<<":"<<endl;
				for(int j=0;j<i;j++){
					for(int k=i+1;k<aa.size();k++){
						if(aa[j]+aa[k]==aa[i]*2){
							cout<<pre[aa[i]][0]<<" "<<pre[aa[i]][1]<<" "<<pre[aa[j]][0]<<" "<<pre[aa[k]][0]<<endl;
							return 0;
						}
					}
				}
			}
		}
	}





	cout<<"NO"<<endl;






 
	return 0;
}