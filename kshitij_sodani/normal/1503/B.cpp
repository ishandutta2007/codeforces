//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second

int n;

void ans(int aa,int i,int j){
	cout<<aa<<" "<<i<<" "<<j<<endl;

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	vector<pair<int,int>> ss;
	vector<pair<int,int>> tt;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if((i+j)%2==1){
				ss.pb({i,j});
			}
			else{
				tt.pb({i,j});
			}
		}
	}
	//fill b in ss
	//fill a in tt
	for(int i=0;i<n*n;i++){
		int a;
		cin>>a;
		pair<int,int> xx;
		int co=0;
		if(a==3){
			if(ss.size()){
				xx=ss.back();
				ss.pop_back();
				co=2;
			}
			else{
				xx=tt.back();
				tt.pop_back();
				co=1;
			}
		}
		else if(a==1){
			if(ss.size()){
				xx=ss.back();
				ss.pop_back();
				co=2;
			}
			else{
				xx=tt.back();
				tt.pop_back();
				co=3;
			}
		}
		else{
			if(tt.size()){
				xx=tt.back();
				tt.pop_back();
				co=1;
			}
			else{
				xx=ss.back();
				ss.pop_back();
				co=3;
			}
		}

		ans(co,xx.a+1,xx.b+1);
	}









 
 
 
	return 0;
}