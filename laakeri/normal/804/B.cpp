#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	ll bs=0;
	ll v=0;
	for (int i=(int)s.size()-1;i>=0;i--){
		if (s[i]=='b') bs++;
		else{
			v+=bs;
			bs+=bs;
		}
		v%=mod;
		bs%=mod;
	}
	cout<<v<<endl;
}