//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo it[2001][2001];
llo ans[11];
llo cur[11];
llo cur2[11];
llo tt[2001][2001];
llo n;
void solve(){
	for(llo i=0;i<10;i++){
			cur[i]=-1;
		}

	for(llo i=n-1;i>=0;i--){
		for(llo i=0;i<10;i++){
			cur2[i]=-1;
		}
		for(llo j=0;j<n;j++){
			if(cur2[it[i][j]]!=-1){
				ans[it[i][j]]=max((j-cur2[it[i][j]])*max(n-i-1,i),ans[it[i][j]]);
			}
			else{
				cur2[it[i][j]]=j;
			}
			if(cur[it[i][j]]!=-1){
				ans[it[i][j]]=max(ans[it[i][j]],(cur[it[i][j]]-i)*max(n-j-1,j));
			}
		}
		for(llo j=0;j<n;j++){
			if(cur[it[i][j]]==-1){
				cur[it[i][j]]=i;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
	//	llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			string s;
			cin>>s;
			for(llo j=0;j<n;j++){
				it[i][j]=s[j]-'0';
			}
		}
		for(llo i=0;i<10;i++){
			ans[i]=0;

		}
		solve();
		for(llo i=0;i<n/2;i++){
			for(llo j=0;j<n;j++){
				swap(it[i][j],it[n-i-1][j]);
			}
		}
		solve();
		for(llo i=0;i<n;i++){
			for(llo j=0;j<n;j++){
				tt[j][i]=it[i][j];
			}
		}
		for(llo i=0;i<n;i++){
			for(llo j=0;j<n;j++){
				it[i][j]=tt[i][j];
			}
		}
		/*for(llo i=0;i<n;i++){
			for(llo j=0;j<n;j++){
				cout<<it[i][j]<<",";
			}
			cout<<endl;
		}
		cout<<endl;*/
		solve();
		for(llo i=0;i<n/2;i++){
			for(llo j=0;j<n;j++){
				swap(it[i][j],it[n-i-1][j]);
			}
		}
		solve();


		
		






		for(llo i=0;i<10;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}






 
 
	return 0;
}