#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
#define endl '\n'
typedef long long llo;

int it[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> ss;
		vector<int> tt;
		for(int i=0;i<n;i++){
			cin>>it[i];
			if((it[i]%2)==(it[0]%2)){
				ss.pb(i);
			}
			else{
				tt.pb(i);
			}
		}
		int ans=tt.size()+ss.size();
		ans--;
		cout<<ans<<endl;
		for(int i=0;i+1<ss.size();i++){
			cout<<ss[i]+1<<" "<<ss.back()+1<<endl;
		}
		for(int i=0;i<tt.size();i++){
			cout<<ss[0]+1<<" "<<tt[i]+1<<endl;
		}

	}




	return 0;
}