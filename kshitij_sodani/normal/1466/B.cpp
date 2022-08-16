//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int it[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		set<int> tt;
		map<int,int> ss;
		for(int i=0;i<n;i++){
			cin>>it[i];
			ss[it[i]]++;
			//ss.insert(it[i]);
		}
		for(auto j:ss){
			if(j.b>=2){
				tt.insert(j.a);
				tt.insert(j.a+1);
			}
		}
		for(auto j:ss){
			if(j.b==1){
				if(tt.find(j.a)==tt.end()){
					tt.insert(j.a);
				}
				else{
					tt.insert(j.a+1);
				}
			}
		}
		cout<<tt.size()<<endl;
		/*for(auto j:ss){
			if(ss.find())
		}*/
	}



 
	return 0;
}