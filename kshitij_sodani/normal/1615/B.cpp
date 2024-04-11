//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo pre[21][200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	for(llo i=0;i<20;i++){
		for(llo j=1;j<=200000;j++){
			pre[i][j]=pre[i][j-1];
			if(j&(1<<i)){
				pre[i][j]++;
			}
		}
	}
	while(t--){
		llo l,r;
		cin>>l>>r;
		llo x=0;
		for(llo i=0;i<20;i++){
			x=max(x,pre[i][r]-pre[i][l-1]);
		}
		cout<<(r-l+1)-x<<endl;
	}






 
	return 0;
}