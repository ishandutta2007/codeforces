//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int pre[1000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	string ss;
	cin>>ss;
	int n=s.size();
	int m=ss.size();
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+s[i-1]-'0';
	}
	int ans=0;
	int co=0;
	for(int i=0;i<m;i++){
		co+=(ss[i]-'0');
	}
	for(int i=0;i<n;i++){
		if(i+m-1<n){
			int x=pre[i+m]-pre[i];
			if((max(x,co)-min(x,co))%2==0){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	



 
	return 0;
}