#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	string s;
	vector<int> cnt(200);
	int n;cin>>s;n=s.size();
	string res;
	int pos=0;
	for(int i=0;i<n;i++){
		cnt[s[i]]++;
	}
	for(int i=0;i<n;i++){
		if(cnt[s[i]]==1)break;
		cnt[s[i]]--;
		pos++;
	}
	for(int i=pos;i<n;i++)cout<<s[i];
	cout<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}