
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n' 

int vis[1000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		set<int> ss;
		for(int i=0;i<n;i++){
			vis[i]=0;
		}
		for(int i=0;i<n;i++){
			int tt=-1;
			if(s[i]=='<'){
				tt=0;
			}
			else if(s[i]=='>'){
				tt=1;
			}
			else{
				vis[i]=1;
				vis[(i+1)%n]=1;
			}
			if(tt>-1){
				ss.insert(tt);
			}
		}
		if(ss.size()<=1){
			cout<<n<<endl;
		}
		else{
			int ans=0;
			for(int i=0;i<n;i++){
				ans+=vis[i];
			}
			cout<<ans<<endl;

		}




	}







	return 0;
}