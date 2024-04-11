
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

int vis[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*vector<int> ss;
	for(int i=2;i<=1e5;i++){
		if(vis[i]==0){
			ss.pb(i);
			for(int j=i;j<=1e5;j+=i){
				vis[j]=1;
			}
		}
	}*/
	llo t;
	cin>>t;

	while(t--){
		llo n;
		cin>>n;
		if(n%2==1){
			cout<<2<<endl;
			continue;
		}
		llo cur=1;
		llo nn=n;
		while(nn%2==0){
			nn/=2;
			cur*=2;
		}
		llo le=n/cur;
		//check cur*2;
		if((2*cur)-1<le){
			cout<<(2*cur)<<endl;
		}
		else if(le==1){
			cout<<-1<<endl;
		}
		else{
			cout<<le<<endl;
		}




	}






	return 0;
}