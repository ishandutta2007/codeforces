#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo it[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	llo t;
	cin>>t;
	while(t--){
		llo n,z;
		cin>>n;

		llo st2=0;
		llo st=0;
		llo su=0;

		for(llo i=0;i<n;i++){
			cin>>it[i];
			if(it[i]==0){
				if(su>0){
					st2=1;
				}
			}
			else{
				if(st2==1){
					st=1;
				}
			}
			su+=it[i];
		}
		if(su==0){
			cout<<0<<endl;
			continue;
		}
		cout<<1+st<<endl;
	}





	return 0;
}