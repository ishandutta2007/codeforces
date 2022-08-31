//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int it[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int ans=-1;
		map<int,int> ss;
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>it[i];
			if(ss.find(it[i])!=ss.end()){
				int cur=ss[it[i]]+n-i;
				ans=max(ans,cur);
			}
			ss[it[i]]=i;
		}
		cout<<ans<<endl;
	}




 
	return 0;
}