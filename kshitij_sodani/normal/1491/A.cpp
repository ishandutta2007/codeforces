//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int it[1000001];
int co[3];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	cin>>n>>q;
	//vector<int> aa;
	for(int i=0;i<n;i++){
		cin>>it[i];
		co[it[i]]++;
		//aa.pb(it[i]);
	}
	//sort(aa.begin(),aa.end());

	//int st=0;

	while(q--){
		int t;
		cin>>t;
		if(t==1){
			int i;
			cin>>i;
			i--;
			co[it[i]]--;
			it[i]=1-it[i];
			co[it[i]]++;
		}
		else{
			int k;
			cin>>k;
			
			if(k<=co[1]){
				cout<<1<<endl;
			}
			else{
				cout<<0<<endl;
			}
		}
	}





 
	return 0;
}