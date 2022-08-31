#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
int n;
int it[100001];
int ans[100001];
int main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>it[i];
		ans[i]=-1;
	}
	set<int> ss;
	for(int i=0;i<=2*n;i++){
		ss.insert(i);
	}
	for(int i=0;i<n;i++){
		ss.erase(it[i]);
	}
 
	for(int i=0;i<n;i++){
		ans[i]=*(ss.begin());
		/*if(ss.size()>1){
			ss.erase(*(ss.begin()));
		}*/
		ss.erase(*(ss.begin()));
		if(i+1<n){
			if(it[i+1]>it[i]){
				ss.insert(it[i]);
			}
		}
		cout<<ans[i]<<" ";
	}
	cout<<endl;
 
 
	/*for(int i=0;i<n-1;i++){
		if(it[i]!=it[i+1]){
			ans[i+1]=it[i];
			ss.erase(it[i]);
		}
	}
	for(int i=0;i<n;i++){
		if(ans[i]==-1){
			ans[i]=*(ss.begin());
 
		}
	}*/
 
 
	return 0;
}