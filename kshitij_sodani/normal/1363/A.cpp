//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int st=0;
		int n,x;
		cin>>n>>x;
		int co=0;
		for(int i=0;i<n;i++){
			int aa;
			cin>>aa;
			if(aa%2==1){
				co++;
			}
		}
		int le=n-co;
		if(co>0){
			if(co%2==0){
				co--;
			}
		}
		if(le==0 and x%2==0){
			cout<<"No"<<endl;
			continue;
		}
		if(le+co>=x and co>0){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}

	}



	return 0;
}