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
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>it[i];
		}
		pair<int,int> mi={it[0],1};
		for(int i=1;i<n;i++){
			if(it[i]<mi.a){
				mi={it[i],1};
			}
			else if(it[i]==mi.a){
				mi.b+=1;
			}
		}
		cout<<n-mi.b<<endl;

	}







	return 0;
}