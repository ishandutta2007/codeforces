//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int it[2][101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string ans="YES";
		for(int i=0;i<2;i++){
			string s;
			cin>>s;
			for(int j=0;j<n;j++){
				it[i][j]=s[j]-'0';
			}
		}
		for(int j=0;j<n;j++){
			if(it[0][j]+it[1][j]==2){
				ans="NO";
			}
		}
		cout<<ans<<endl;
	}
	
 
 
	return 0;
}