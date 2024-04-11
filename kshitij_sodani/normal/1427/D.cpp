
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n' 

int it[101];
int n;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>it[i];
		it[i]--;
	}
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	vector<vector<int>> ans;
	int co=0;
	int co2=0;
	for(int i=0;i<n;i++){
		vector<int> kk;
		for(int j=0;j<co;j++){
			kk.pb(1);
		}
		int stt=0;
	//	cout<<i<<":"<<co<<":"<<co2<<endl;
		if((n-i-1)%2==0){
			int ind=-1;
			for(int j=co;j<n-co2;j++){
				if(it[j]==i){
					ind=j;
				}
			}
		//	cout<<ind<<"?"<<endl;
			int cot=0;
			if(ind-co>0){
				kk.pb(ind-co);
				cot=ind-co;
			}
			kk.pb(n-cot-co-co2);
		//	co++;
		}
		else{
			int ind=-1;
			for(int j=co;j<n-co2;j++){
				if(it[j]==i){
					ind=j;
				}
			}
			
			kk.pb(ind+1-co);
			if(n-kk.back()-co-co2>0){
				kk.pb(n-kk.back()-co-co2);
			}
			//co2++;
			stt=1;
		}



		for(int j=0;j<co2;j++){
			kk.pb(1);
		}

		/*for(auto j:kk){
			cout<<j<<" ";
		}
		cout<<endl;*/
		swap(co,co2);
		if(stt==0){
			co+=1;
		}
		else{
			co2++;
		}
		if(kk.size()>1){
			ans.pb(kk);
		}
		vector<vector<int>> tt;
		int cur=0;
		for(auto j:kk){
			vector<int> ac;
			for(int ii=0;ii<j;ii++){
				ac.pb(it[cur]);
				cur++;
			}
			tt.pb(ac);
		}
		reverse(tt.begin(),tt.end());
		cur=0;
		for(auto j:tt){
			for(auto ii:j){
				it[cur]=ii;
				cur++;
			}
		}
	/*	for(int ii=0;ii<n;ii++){
			cout<<it[ii]<<",,";
		}
		cout<<endl;
		cout<<11<<endl;*/
	}	
	/*for(int i=0;i<n;i++){
		cout<<it[i]<<",";
	}
	cout<<endl;*/
	cout<<ans.size()<<endl;
	for(auto j:ans){
		cout<<j.size()<<" ";
		for(auto i:j){
			cout<<i<<" ";
		}
		cout<<endl;
	}



	return 0;
}