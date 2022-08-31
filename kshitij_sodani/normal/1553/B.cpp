//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin>>q;
	while(q--){
		string s;
		cin>>s;
		string t;
		cin>>t;
		int n=s.size();
		int m=t.size();
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				if(j-i+1>m){
					continue;
				}
				if((j-i+1)+j<m){
					continue;
				}
				string tt="";
				for(int k=i;k<=j;k++){
					tt+=s[k];
				}
				for(int k=j-1;k>=j-(m-(j-i+1));k--){
					tt+=s[k];
				}
				if(tt==t){
					ans=1;
				}
			}
		}
		if(ans==0){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
	}
 
 

 
 
 
	return 0;
}