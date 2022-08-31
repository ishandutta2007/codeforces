//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int t;
int it[300001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>it[i];
		}
		for(int i=0;i<n;i++){
			int cur=it[i];
			if(i%2==0){
				cur=abs(cur);
			}
			else{
				cur=-abs(cur);
			}
			cout<<cur<<" ";
		}
		cout<<endl;
		
	}











 
	return 0;
}