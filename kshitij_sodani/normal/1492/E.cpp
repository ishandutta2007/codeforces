//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int n,m;
int co2[300001];
int co[300001];
vector<int> it[300001];
int cot[300001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int aa;
			cin>>aa;
			it[i].pb(aa);
			if(it[i][j]!=it[0][j]){
				co[i]++;
			}
		}
	}
	int ma=0;
	for(int i=0;i<n;i++){
		ma=max(ma,co[i]);
	}
	if(ma>4){
		cout<<"NO"<<endl;
		return 0;
	}
	if(ma<=2){
		cout<<"YES"<<endl;
		for(int i=0;i<m;i++){
			cout<<it[0][i]<<" ";
		}
		cout<<endl;
		return 0;
	}
	int cur=0;
	int ind=-1;
	for(int i=0;i<n;i++){
		if(co[i]>cur){
			cur=co[i];
			ind=i;
		}
	}
	vector<int> ss;
	for(int j=0;j<m;j++){
		if(it[ind][j]!=it[0][j]){
			ss.pb(j);
		}
	}
	for(int i=0;i<n;i++){
		co2[i]=co[i];
	}
	for(auto j:ss){
		for(int i=0;i<n;i++){
			co[i]=co2[i];
		}
		for(int i=0;i<n;i++){

			if(it[i][j]!=it[0][j]){
				co[i]--;
			}
			if(it[i][j]!=it[ind][j]){
				co[i]++;
			}
		}
		int cur2=0;
		int ind2=-1;
		for(int i=0;i<n;i++){
			if(co[i]>cur2){
				cur2=co[i];
				ind2=i;
			}
		}
		for(int i=0;i<m;i++){
			if(i==j){
				cot[i]=it[ind][i];
			}
			else{
				cot[i]=it[0][i];
			}
		}
		if(cur2<=2){
			cout<<"YES"<<endl;
			/*cout<<j<<","<<ind<<endl;
			for(int i=0;i<n;i++){
				cout<<co[i]<<",,";
			}	
			cout<<endl;*/
			for(int i=0;i<m;i++){
				cout<<cot[i]<<" ";

			}
			cout<<endl;
			return 0;
		}
		vector<int> tt;
		for(int i=0;i<m;i++){
			if(it[ind2][i]!=cot[i]){
				if(i!=j){
					tt.pb(i);
				}
			}
		}
		for(auto jj:tt){
			int xx=cot[jj];
			cot[jj]=it[ind2][jj];
			for(int i=0;i<n;i++){

				if(it[i][jj]!=it[0][jj]){
					co[i]--;
				}
				if(it[i][jj]!=it[ind2][jj]){
					co[i]++;
				}
			}
			int maa=0;
			for(int i=0;i<n;i++){
				maa=max(maa,co[i]);

			}
			if(maa<=2){
				cout<<"YES"<<endl;
				for(int i=0;i<m;i++){
					cout<<cot[i]<<" ";
				}
				cout<<endl;
				return 0;
			}

			cot[jj]=xx;

			for(int i=0;i<n;i++){

				if(it[i][jj]!=it[0][jj]){
					co[i]++;
				}
				if(it[i][jj]!=it[ind2][jj]){
					co[i]--;
				}
			}
		}



	}

	cout<<"NO"<<endl;








 
	return 0;
}