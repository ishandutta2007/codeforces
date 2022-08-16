#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

int it[101][101];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			for(int j=0;j<m;j++){
				it[i][j]=s[j]-'0';
			}
		}
		string ans="YES";
		for(int i=0;i<n-1;i++){
			for(int j=0;j<m-1;j++){
				if(it[i][j]+it[i+1][j]+it[i][j+1]+it[i+1][j+1]==3){
					ans="NO";
				}
			}
		}
		cout<<ans<<endl;
	}





	return 0;
}