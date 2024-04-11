//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'

int ask(vector<int> aa,vector<int> bb){
	cout<<"? "<<(aa.size())<<" "<<bb.size()<<endl;
	for(auto j:aa){
		cout<<j+1<<" ";
	}
	cout<<endl;
	for(auto j:bb){
		cout<<j+1<<" ";
	}
	cout<<endl;
	int xx;
	cin>>xx;
	return xx;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		vector<int> cc;
		int n;
		cin>>n;
		for(int i=1;i<n;i++){
			cc.pb(i-1);
			int xx=ask(cc,{i});
			if(xx!=0){
				//vector<int> ans;
				int low=-1;
				for(int j=19;j>=0;j--){
					if((1<<j)+low<i-1){
						vector<int> dd;
						for(int ii=0;ii<=(1<<j)+low;ii++){
							dd.pb(ii);
						}
						if(ask(dd,{i})==0){
							low+=(1<<j);
						}
					}
				}
				vector<int> ans;
				for(int j=0;j<i;j++){
					if(j!=low+1){
						ans.pb(j);
					}
				}
				for(int j=i+1;j<n;j++){
					if(ask({low+1,j},{i})==xx){
						ans.pb(j);
					}
				}
				cout<<"! ";
				cout<<ans.size()<<" ";
				for(auto j:ans){
					cout<<j+1<<" ";
				}
				cout<<endl;


				break;
			}
		}
	}


 
	return 0;
}