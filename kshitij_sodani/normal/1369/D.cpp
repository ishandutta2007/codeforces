#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
llo mod=1e9+7;
llo pre[2000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	pre[1]=0;
	pre[2]=0;
	for(int i=3;i<2000001;i++){
		pre[i]=pre[i-1]+pre[i-2]*2;
		if(i%3==0){
			pre[i]+=4;
		}
		pre[i]%=mod;
	}

	while(t--){
		int n;
		cin>>n;
		cout<<pre[n]<<'\n';
		
	}







	return 0;
}