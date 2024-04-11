
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n' 
int n;
vector<int> co;
vector<int> kk[101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	if(n==1){
		cout<<"? 1 1"<<endl;
		string s;
		cin>>s;
		cout<<"! "<<s<<endl;
		return 0;
	}
	for(int i=0;i<26;i++){
		co.pb(0);
	}
	cout<<"? 1 "<<n<<endl;
	map<vector<int>,int> ss;
	for(int i=0;i<(n*(n+1))/2;i++){
		string s;
		cin>>s;
		for(int j=0;j<26;j++){
			co[j]=0;
		}
		for(int j=0;j<s.size();j++){
			co[s[j]-'a']++;
		}
		ss[co]++;
	}
	cout<<"? 1 "<<n-1<<endl;
	for(int i=0;i<(n*(n-1))/2;i++){
		string s;
		cin>>s;
		for(int j=0;j<26;j++){
			co[j]=0;
		}
		for(int j=0;j<s.size();j++){
			co[s[j]-'a']++;
		}
		ss[co]--;
	}
	for(int i=0;i<26;i++){
		kk[0].pb(0);
	}
	for(auto j:ss){
		if(j.b>0){
			int su=0;
			for(int i=0;i<26;i++){
				su+=j.a[i];
			}
			kk[su]=j.a;
		}
	}
	vector<char> ans;
	string s="abcdefghijklmnopqrstuvwxyz";
	for(int j=1;j<=n;j++){
		for(int k=0;k<26;k++){
			if(kk[j][k]>kk[j-1][k]){
				ans.pb(s[k]);
			}
		}
	}
	cout<<"! ";
	for(int i=n-1;i>=0;i--){
		cout<<ans[i];
	}
	cout<<endl;;




	return 0;
}