//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int aa[100001];
int bb[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	llo t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				aa[i]=0;
			}
			else{
				aa[i]=1;
			}
		}
		cin>>s;
		int ans=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				bb[i]=0;
			}
			else{
				bb[i]=1;
			}
		}
		int ss=-1;

		for(int i=0;i<n;i++){
			//cout<<ans<<":";
			if(aa[i]+bb[i]==1){
				if(ss==0){
					ans++;
				}
				ans+=2;
				ss=-1;
				continue;
			}
			if(aa[i]+bb[i]==2){
				if(ss==0){
					ans+=2;
					ss=-1;
					continue;
				}
				ss=1;
			}
			else{
				if(ss==1){
					ans+=2;
					ss=-1;
					continue;
				}
				if(ss==0){
					ans++;
				}
				ss=0;
			}
		}
		if(ss==0){
			ans++;
		}

		cout<<ans<<endl;

	}


 
 
 
	return 0;
}