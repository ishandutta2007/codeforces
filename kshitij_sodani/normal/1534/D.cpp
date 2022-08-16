#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
typedef long long llo;
int n;
vector<int> ask(int i){
	cout<<"? "<<i+1<<endl;
	vector<int> xx;
	for(int j=0;j<n;j++){
		int y;
		cin>>y;
		xx.pb(y);
	}
	return xx;

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	vector<int> aa;
	vector<int> bb;
	vector<pair<int,int>> ans;
	vector<int> cc=ask(0);
	for(int i=0;i<n;i++){
		if(cc[i]%2==0){
			aa.pb(i);
		}
		else{
			bb.pb(i);
		}
		if(cc[i]==1){
			ans.pb({0,i});
		}
	}
	if((aa.size())<=bb.size()+1){
		for(auto j:aa){
			if(j!=0){
				cc=ask(j);
				for(int i=0;i<n;i++){
					if(cc[i]==1 and i!=0){
						ans.pb({j,i});
					}
				}
			}
		}
	}
	else{
		for(auto j:bb){
			if(j!=0){
				cc=ask(j);
				for(int i=0;i<n;i++){
					if(cc[i]==1 and i!=0){
						ans.pb({j,i});
					}
				}
			}
		}


	}
	cout<<"!"<<endl;
	for(auto j:ans){
		cout<<j.a+1<<" "<<j.b+1<<endl;
	}






	return 0;
}