#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
#define endl '\n'
typedef long long llo;
int par[200001];
int find(int no){
	if(par[no]==no){
		return no;
	}
	par[no]=find(par[no]);
	return par[no];
}
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
		vector<int> ss;
		for(int i=0;i<2*n;i++){
			par[i]=i;
		}
		for(int i=0;i<2*n;i++){
			if(s[i]=='('){
				ss.pb(i);
			}
			else{
				int xx=ss.back();
				ss.pop_back();
				int x=find(xx);
				int y=find(i);
				par[x]=y;
				if(i+1<2*n and s[i+1]=='('){
					x=find(i);
					y=find(i+1);
					par[x]=y;
				}

			}
		}
		int ans=0;
		for(int i=0;i<2*n;i++){
			if(par[i]==i){
				ans++;
			}
		}
		cout<<ans<<endl;
	}






	return 0;
}