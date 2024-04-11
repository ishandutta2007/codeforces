//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'


llo t;
llo it[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		set<llo> ss;
		llo st=1;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			if(i>=100){
				continue;
			}
			llo ok=0;
			for(llo j=i;j>=0;j--){
				if((it[i]%(j+2))>0){
					ok=1;
				}
			}
			if(ok==0){
				st=0;
			}
		}
		if(st==1){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}





 
	return 0;
}