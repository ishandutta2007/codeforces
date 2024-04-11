#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'


int aa[51];
int bb[51];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		string s;
		cin>>s;
		string ss;
		cin>>ss;
		for(int i=0;i<n;i++){
			aa[i]=s[i]-'0';
		}
		for(int i=0;i<m;i++){
			bb[i]=ss[i]-'0';
		}
		int st=1;
		int ind=n-1;
		for(int i=m-1;i>=1;i--){
			if(bb[i]!=aa[ind]){
				st=0;
			}
			ind--;
		}
		int ok=0;
		for(int i=0;i<=ind;i++){
			if(bb[0]==aa[i]){
				ok=1;
			}
		}
		if(ok==1 and st==1){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}








	return 0;
}