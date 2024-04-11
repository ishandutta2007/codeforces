//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo pre[1001];
llo it[1001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,m;
		cin>>n>>m;
		string s;
		cin>>s;
		for(llo i=0;i<n;i++){
			it[i]=s[i]-'0';
			pre[i+1]=pre[i]+it[i];
		}
		for(llo i=0;i<n;i++){
			llo cur=-1;
			if(it[i]==1){
				cout<<1;
				continue;
			}
			for(llo j=i-1;j>=i-m;j--){
				if(j<0){
					break;
				}
				if(it[j]==1){
					cur=j;
					break;
				}
			}
			llo cur2=-1;
			for(llo j=i+1;j<=i+m;j++){
				if(j>=n){
					break;
				}
				if(it[j]==1){
					cur2=j;
					break;
				}
			}
			if(cur==-1 and cur2==-1){
				cout<<0;
			}
			else if(cur>=0 and cur2>=0){
				if((i-cur)==(cur2-i)){
					cout<<0;
				}
				else{
					cout<<1;
				}
			}
			else{
				cout<<1;
			}

		}
		cout<<endl;

	}








	return 0;
}