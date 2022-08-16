#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define a first
#define b second
#define pb push_back
llo mod=100000007;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int re[n*m][22];
		int it[n*m];
		char s;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>s;
				if(s=='0'){
					it[i*m+j]=1;
				}
				else{
					it[i*m+j]=0;
				}

			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>s;
				if(s=='L'){
					re[i*m+j][0]=i*m+j-1;
				}
				else if(s=='R'){
					re[i*m+j][0]=i*m+j+1;
				}
				else if(s=='U'){
					re[i*m+j][0]=(i-1)*m+j;
				}
				else{
					re[i*m+j][0]=(i+1)*m+j;
				}
			}
		}
		for(int i=1;i<22;i++){
			for(int j=0;j<n*m;j++){
				re[j][i]=re[re[j][i-1]][i-1];
			}
		}
		int aa[n*m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				aa[i*m+j]=0;
			}
		}
		vector<int> bb;
		int cc=n*m;
		for(int i=0;i<22;i++){
			if((1<<i)&(cc)){
				bb.pb(i);
			}
		}
		for(int i=0;i<n*m;i++){
			int no=i;
			for(auto j:bb){
				no=re[no][j];
			}
			no=re[i][21];
			if(it[i]==1){
				aa[no]=2;
			}
			else{
				aa[no]=max(aa[no],1);
			}
		}
		int ans=0;
		int ans2=0;
		for(int i=0;i<n*m;i++){
			if(aa[i]==1){
				ans+=1;
			}
			else if(aa[i]==2){
				ans+=1;
				ans2+=1;
			}
		}
		cout<<ans<<" "<<ans2<<endl;
	}
	return 0;
}