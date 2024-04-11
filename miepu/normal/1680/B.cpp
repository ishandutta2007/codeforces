#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	string s[6];
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(s[i][j]=='R'){
				int fl=1;
				for(int x=0;x<i;x++)
					for(int y=0;y<m;y++)	
						fl&=s[x][y]!='R';
				for(int x=0;x<n;x++)
					for(int y=0;y<j;y++)	
						fl&=s[x][y]!='R';
				if(fl){
					cout<<"YES"<<endl;
					return;
				}
			}
	cout<<"NO"<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}