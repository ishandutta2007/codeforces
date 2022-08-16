
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 
int t;
int aa[101];
int bb[101];
int cc[101];
int it[101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			it[i]=0;
		}
		for(int i=0;i<n;i++){
			cin>>aa[i];
		}
		for(int i=0;i<n;i++){
			cin>>bb[i];
		}
		for(int i=0;i<n;i++){
			cin>>cc[i];
		}
		for(int i=0;i<n;i++){
			if(aa[i]!=(it[(i-1)%n]) and aa[i]!=it[(i+1)%n]){
				cout<<aa[i]<<" ";
				it[i]=aa[i];
			}
			else if(bb[i]!=(it[(i-1)%n]) and bb[i]!=it[(i+1)%n]){
				cout<<bb[i]<<" ";
				it[i]=bb[i];
			}
			else if(cc[i]!=(it[(i-1)%n]) and cc[i]!=it[(i+1)%n]){
				cout<<cc[i]<<" ";
				it[i]=cc[i];
			}
		}
		cout<<endl;


	}








	return 0;
}