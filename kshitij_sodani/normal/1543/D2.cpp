//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'

bool ask(llo i){
	cout<<i<<endl;
	llo x;
	cin>>x;
	return x;
}
vector<llo> pre[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	llo t;
	cin>>t;
	while(t--){
		llo n,k;
		cin>>n>>k;
		vector<llo> ss;
	//	llo cur=0;
		for(llo i=0;i<n;i++){
			llo cur=i;
			pre[i].clear();
			while(cur>0){
				pre[i].pb(cur%k);
				cur/=k; }
		}
		for(llo i=0;i<n-1;i++){
			while(pre[i].size()<pre[n-1].size()){
				pre[i].pb(0);
			}
		}
		vector<llo> cur;
		for(llo i=0;i<pre[n-1].size();i++){
			cur.pb(0);
		}
		/*for(llo i=0;i<n;i++){
			for(auto j:pre[i]){
				cout<<j<<",";
			}
			cout<<endl;
		}*/
		for(llo i=0;i<n;i++){
			/*if(ask(cur^i)){
				break;
			}*/
			vector<llo> cur2=pre[i];
			/*for(int j=0;j<cur.size();j++){
				cur[j]=(k-cur[j])%k;
			}*/
			vector<llo> cur4=cur;
			
			for(llo j=0;j<cur.size();j++){
				//cout<<pre[i][j]<<":"<<cur[j]<<",";
				cur[j]=(pre[i][j]-cur[j]+k)%k;
			}

			if(i%2==1){
				for(int j=0;j<cur.size();j++){
					cur[j]=(k-cur[j])%k;
				}
			}
			//cout<<endl;
			llo kk=0;
			llo cur3=1;
			for(auto j:cur){
				kk+=cur3*j;
				cur3*=k;
			}
			if(ask(kk)){
				break;
			}
			if(i%2==0){
				for(llo j=0;j<cur.size();j++){
					//cout<<pre[i][j]<<":"<<cur[j]<<",";
					cur[j]=(cur[j]+cur4[j]+k)%k;
				}
			}
			else{
				for(llo j=0;j<cur.size();j++){
					//cout<<pre[i][j]<<":"<<cur[j]<<",";
					cur[j]=(-cur[j]+cur4[j]+k)%k;
				}
			}
			//cur=pre[i];
			
		}

		/*for(llo i=0;i<n;i++){
			ss.pb(i);
		}
		llo st=0;
		while(true){
			set<llo> xx;
			llo cur=0;
			llo ok=1;
			for(auto j:ss){
				cur^=j;
				if(cur>=n){
					cur=0;
				}
				xx.insert(cur);
			}
			if(xx.size()<n){
				ok=0;
			}
			st|=ok;
			if(next_permutation(ss.begin(),ss.end())){
				continue;
			}
			break;
		}
		cout<<st<<endl;*/
	}



 
 
 
 
 
 
 
	return 0;
}