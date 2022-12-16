#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1001001;
const int MOD=1e9+7;
char s[N];
void work(){
	int x;
	cin>>x;
	cin>>s;
	// cerr<<x<<" "<<s<<endl;
	int n=strlen(s);
	int len=n;
	for(int i=0;i<x;i++){
		int a=s[i]^'0';
		len=(len+(LL)(a-1)*(((LL)len-i-1+2*MOD)%MOD))%MOD;
		int m=min(n+(a-1)*(n-i-1),x);
		for(int j=n;j<m;j++){
			s[j]=s[(j-n)%(n-i-1)+i+1];
		}
		n=m;
	}
	cout<<len<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		work();
	}
	return 0;
}