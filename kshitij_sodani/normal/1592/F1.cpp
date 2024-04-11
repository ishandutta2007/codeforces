//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int n,m;
int it[601][601];
int aa[601][601];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<m;j++){
			if(s[j]=='B'){
				it[i][j]=1;
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			aa[i][j]=(it[i][j]+it[i+1][j]+it[i][j+1]+it[i+1][j+1])%2;
			if(aa[i][j]==1){
				ans++;
			}
		}
	}

	int st=0;
	/*cout<<it[n-1][m-1]<<endl;
	cout<<aa[n-1][m-1]<<endl;*/
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m-1;j++){
			if(aa[i][j]==1 and aa[n-1][j]==1 and aa[i][m-1]==1 and aa[n-1][m-1]==1){
				st=1;
			}
		}
	}
	//cout<<ans<<endl;
	ans-=st;
	cout<<ans<<endl;


 
 
 
	return 0;
}