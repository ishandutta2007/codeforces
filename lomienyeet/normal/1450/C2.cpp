#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
void solve(){
	int n;
	cin>>n;
	string s[n];
	for(int i=0;i<n;i++)cin>>s[i];
	int f[3]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(s[i][j]!='.')f[(i+j+(s[i][j]=='X'))%3]++;
		}
	}
	int mini=0;
	for(int i=0;i<3;i++){
		if(f[i]<f[mini])mini=i;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(s[i][j]!='.'){
				if((i+j)%3==mini)s[i][j]='X';
				else if((i+j+1)%3==mini)s[i][j]='O';
			}
		}
	}
	for(int i=0;i<n;i++)cout<<s[i]<<"\n";
}
signed main(){
	int t;
	cin>>t;
	while(t--)solve();
}