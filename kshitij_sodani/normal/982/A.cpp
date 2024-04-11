//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int it[1001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		it[i]=s[i]-'0';
	}
	string ans="Yes";
	for(int i=0;i<n-1;i++){
		if(it[i]+it[i+1]==2){
			ans="No";
		}
	}
	for(int i=0;i<n;i++){
		if(it[i]==0){
			int st=1;
			if(i>0){
				if(it[i-1]==1){
					st=0;
				}
			}
			if(i+1<n){
				if(it[i+1]==1){
					st=0;
				}
			}
			if(st==1){
				ans="No";
			}
		}
	}
	cout<<ans<<endl;




 
	return 0;
}