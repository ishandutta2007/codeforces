//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'


int t;
int aa,bb;
int n;
int it[1<<22];
int ind[1<<22];
int ind2[1<<22];
int de[1<<22];
int lev[1<<22];
void re2(int no){
	if(it[no*2+1]==0 and it[no*2+2]==0){
		de[no]=lev[no];
		return ;
	}
	if(it[no*2+2]>it[no*2+1]){
		de[no]=de[no*2+2];
	}
	else{
		de[no]=de[no*2+1];
	}


}
void re(int no){
	
	if(it[no*2+1]==0 and it[no*2+2]==0){

		it[no]=0;
		de[no]=-1;
		return;
	}
	if(it[no*2+2]>it[no*2+1]){
		it[no]=it[no*2+2];
		ind2[no]=ind2[no*2+2];
		ind[ind2[no*2+2]]=no;
		re(no*2+2);
	}
	else{
		it[no]=it[no*2+1];
		ind2[no]=ind2[no*2+1];
		ind[ind2[no*2+1]]=no;
		re(no*2+1);
	}

	if(it[no*2+1]==0 and it[no*2+2]==0){
		de[no]=lev[no];
		return ;
	}
	if(it[no*2+2]>it[no*2+1]){
		de[no]=de[no*2+2];
	}
	else{
		de[no]=de[no*2+1];
	}




}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	int cur=0;
	for(int i=0;i<20;i++){
		for(int j=0;j<(1<<i);j++){
			lev[cur]=i;
			cur++;
		}
	}
	while(t--){
		cin>>aa>>bb;
		n=(1<<aa)-1;
		vector<pair<int,int>> ss;
		llo ans=0;
		vector<int> tt;
		for(int i=0;i<3*n;i++){
			it[i]=0;
		}
		for(int i=0;i<n;i++){
			cin>>it[i];
			ans+=it[i];
			ind[i]=i;
			ind2[i]=i;
			de[i]=aa-1;
			ss.pb({it[i],i});
		}
		sort(ss.begin(),ss.end());

		for(int i=0;i<(1<<aa)-(1<<bb);i++){
		//	cout<<de[0]<<":";
			while(ss.size()){
				if(de[ind[ss.back().b]]>=bb){
					int cot=ind[ss.back().b];

					re(ind[ss.back().b]);
					ans-=ss.back().a;
					tt.pb(ind[ss.back().b]);
					if(cot>0){
						cot/=2;
						re2(cot);
					}
					ss.pop_back();
					break;
				}
				else{
					ss.pop_back();
					continue;
				}
			}
		}
		//cout<<endl;
		cout<<ans<<endl;
		for(auto j:tt){
			cout<<j+1<<" ";
		}
		cout<<endl;


		
	}












 
	return 0;
}