#include <bits/stdc++.h>
using namespace std;
const int M=1e9+7;
int n;string S[100010];
int gh[1000010];
int gval(string C){
	int ret=0;for(int i=0;i<C.size();i++)ret=ret*26+C[i];
	return ret;
}
void solve(){
	cin>>n;bool ok=false;
	for(int i=0;i<n;i++){
		cin>>S[i];
		gh[gval(S[i])]++;
		string T=S[i];reverse(T.begin(),T.end());
		int cval=gval(T);
		ok|=gh[cval];
		for(int j='a';j<='z';j++)ok|=gh[min(cval*26+j,1000000)];
		T.pop_back();ok|=gh[gval(T)];
	}
	if(ok)cout<<"YES\n";else cout<<"NO\n";
	for(int i=0;i<n;i++)gh[gval(S[i])]--;	
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}