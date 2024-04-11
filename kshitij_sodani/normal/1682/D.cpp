#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

int it[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int su=0;
		int ok=0;
		for(int i=0;i<n;i++){
			it[i]=s[i]-'0';
			su+=it[i];
			if(it[i]==1){
				ok=1;
			}
		}
		if(su%2==1 or ok==0){
			cout<<"No"<<endl;
			continue;
		}
		vector<pair<int,int>> ans;
		vector<int> tt;
		for(int i=0;i<n;i++){
			if(it[i]==1){
				int cur=i;
				while(true){
					int cur2=cur;
					cur=(cur+n-1)%n;
					if(it[cur]==1){
						tt.pb(cur2);
						break;
					}
					ans.pb({cur2,cur});
				}
			}
		}
		for(int i=1;i<tt.size();i++){
			ans.pb({tt[0],tt[i]});
		}
		cout<<"YES"<<endl;
		for(auto j:ans){
			cout<<j.a+1<<" "<<j.b+1<<endl;
		}


	}











	return 0;
}