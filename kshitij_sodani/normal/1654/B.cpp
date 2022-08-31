#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
int vis[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n=s.size();
		for(int i=0;i<n;i++){
			vis[i]=0;
		}
		set<int> cur;
		for(int i=n-1;i>=0;i--){
			if(cur.find(s[i]-'a')!=cur.end()){
				vis[i]=1;
			}
			cur.insert(s[i]-'a');
		}
		int ind=0;
		for(int i=0;i<n;i++){
			if(vis[i]==0){
				ind=i;
				break;
			}
		}
		for(int i=ind;i<n;i++){
			cout<<s[i];
		}
		cout<<endl;
	}




	return 0;
}