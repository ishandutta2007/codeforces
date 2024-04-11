
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 



int n;
int it[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	vector<llo> cc;
	int co=-1;
	vector<pair<llo,llo>> kk;
	for(int ii=0;ii<2*n;ii++){
		char x;
		cin>>x;
		if(x=='+'){
			co+=1;
			cc.pb(co);
			kk.pb({0,co});
		}
		else{
			if(cc.size()==0){
				cout<<"NO"<<endl;
				return 0;
			}
			int x;
			cin>>x;
			it[cc.back()]=x;
			cc.pop_back();
			kk.pb({1,x});
		}
	}
	set<int> xx;
	for(auto j:kk){
		if(j.a==0){
			xx.insert(it[j.b]);
		}
		else{
			if(j.b!=*xx.begin()){
				cout<<"NO"<<endl;
				return 0;
			}
			xx.erase(xx.begin());
		}
	}
	cout<<"YES"<<endl;

	for(int i=0;i<n;i++){
		cout<<it[i]<<" ";
	}
	cout<<endl;


	return 0;
}