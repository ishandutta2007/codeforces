#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

int t;
int it[51];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int su=0;
		for(int i=0;i<n;i++){
			cin>>it[i];
			su+=it[i]-1;
		}
		if(su%2==0){
			cout<<"maomao90"<<endl;
		}
		else{
			cout<<"errorgorn"<<endl;
		}


	}








	return 0;
}