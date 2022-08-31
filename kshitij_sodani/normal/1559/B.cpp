//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int it[101];
int ans[101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		//int ans2=0;
		for(int i=0;i<n;i++){
			it[i]=-1;
			if(s[i]=='R'){
				it[i]=1;
			}
			else if(s[i]=='B'){
				it[i]=0;
			}
			else{
				if(i>0 and it[i-1]!=-1){
					it[i]=1-it[i-1];
				}
			}
			if(i>0){
				//if(it[i]!=it[i-1]){
					/*if(it[i]!=-1 and it[i-1]!=-1){
						ans++;
					}*/
					if(it[i-1]==-1){
						for(int j=i-1;j>=0;j--){
							it[j]=it[j+1]^1;
						}
					}
				//}
			}
		}

		for(int i=0;i<n;i++){
			if(it[n-1]==-1){
				if(i%2==0){
					cout<<"B";
				}
				else{
					cout<<"R";
				}
				continue;
			}
			if(it[i]==0){
				cout<<"B";
			}
			else{
				cout<<"R";
			}
		}
		cout<<endl;
	}
	



 
	return 0;
}