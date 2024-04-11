#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define a first
#define b second
typedef long long llo;
#define endl "\n"
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int aa[n];
		int co[n];
		int ind[n];
		for(int i=0;i<n;i++){
			cin>>aa[i];
			co[i]=1;
			ind[aa[i]-1]=i;
		}
		int st=1;
		set<int> bb;
		for(int i=0;i<n;i++){
			bb.insert(i);
		}
		multiset<int> xx;
		for(int i=0;i<n;i++){
			xx.insert(-1);
		}
		for(int i=0;i<n;i++){
			int x=ind[i];
			if(co[x]!=-(*(xx.begin()))){
				st=0;
				break;
			}
			auto it=bb.upper_bound(x);
			/*for(int j=0;j<n;j++){
				cout<<co[j]<<" ";

			}*/
			if(it==bb.end()){
				int yy=1;
			}
			else{

				auto te=xx.find(-co[*it]);
				xx.erase(te);
				co[*it]+=co[x];
				xx.insert(-co[*it]);
			}
			auto tt=xx.find(-co[x]);
			xx.erase(tt);
			co[x]=0;
			bb.erase(x);
		}
		if(st==1){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}


	return 0;
}