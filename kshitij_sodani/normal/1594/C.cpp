//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int vis[300001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		char s;
		cin>>s;
		int x=s-'a';
		string ss;
		cin>>ss;
		vector<int> ind;
		for(int i=0;i<n;i++){
			if(ss[i]-'a'!=x){
				ind.pb(i+1);
			}
			vis[i+1]=0;
		}
		if(ind.size()==0){
			cout<<0<<endl;
		}
		else{
			for(auto j:ind){
				vis[j]=1;
			}
			int ok=0;
			for(int i=1;i<=n;i++){
				int st=1;
				for(int j=i;j<=n;j+=i){
					if(vis[j]==1){
						st=0;
					}
				}
				if(st==1){
					cout<<1<<endl;
					cout<<i<<endl;
					ok=1;
					break;
				}
			}
			if(ok==0){
				cout<<2<<endl;
				cout<<n<<" "<<n-1<<endl;
			}
		}
	}


 
 
 
	return 0;
}