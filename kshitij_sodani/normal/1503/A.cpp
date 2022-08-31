//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'


int t;
int it[200001];
int ans[200001];
int ans2[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	


	cin>>t;

	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int co=0;
		vector<int> ss;
		vector<int> tt;
		for(int i=0;i<n;i++){
			it[i]=s[i]-'0';
			if(it[i]==0){
				co++;
				tt.pb(i);
			}
			else{
				ss.pb(i);
			}
		}
		if(it[0]==0 or it[n-1]==0 or (co%2==1)){
			cout<<"NO"<<endl;
			continue;
		}
		for(int i=0;i<(ss.size()/2);i++){
			ans[ss[i]]=1;
			ans2[ss[i]]=1;
		}
		for(int i=(ss.size()/2);i<ss.size();i++){
			ans[ss[i]]=-1;
			ans2[ss[i]]=-1;
		}
		for(int i=0;i<(tt.size());i+=2){
			ans[tt[i]]=1;
			ans2[tt[i]]=-1;
		}
		for(int i=1;i<(tt.size());i+=2){
			ans[tt[i]]=-1;
			ans2[tt[i]]=1;
		}
		llo st=1;
		llo su=0;
		for(int i=0;i<n;i++){
			su+=ans[i];
			if(su<0){
				st=0;
			}
		}
		su=0;
		for(int i=0;i<n;i++){
			su+=ans2[i];
			if(su<0){
				st=0;
			}
		}
		if(st==0){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++){
			if(ans[i]==1){
				cout<<'(';
			}
			else{
				cout<<')';
			}
		}
		cout<<endl;
		for(int i=0;i<n;i++){
			if(ans2[i]==1){
				cout<<'(';
			}
			else{
				cout<<')';
			}
		}
		cout<<endl;







	}










 
 
 
	return 0;
}