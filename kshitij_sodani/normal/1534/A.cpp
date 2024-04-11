#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
typedef long long llo;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int st=1;
		int st2=1;
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			for(int j=0;j<m;j++){
				if(s[j]=='R'){
					if((i+j)%2==0){
						st=0;
					}
					else{
						st2=0;
					}
				}
				else if(s[j]=='W'){
					if((i+j)%2==1){
						st=0;
					}
					else{
						st2=0;
					}
				}
			}
		}
		if(st){
			cout<<"YES"<<endl;
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if((i+j)%2==1){
						cout<<"R";
					}
					else{
						cout<<"W";
					}
				}
				cout<<endl;
			}
			
		}
		else if(st2){
			cout<<"YES"<<endl;
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if((i+j)%2==0){
						cout<<"R";
					}
					else{
						cout<<"W";
					}
				}
				cout<<endl;
			}
			

		}
		else{
			cout<<"NO"<<endl;
		}
	}






	return 0;
}