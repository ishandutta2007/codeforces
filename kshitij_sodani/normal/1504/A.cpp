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
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int st=1;
		int n=s.size();
		int ind=-1;
		for(int i=0;i<n;i++){
			if(s[i]=='a'){
				
			}
			else{
				ind=i;
				st=0;
			}
		}
		if(st==1){
			cout<<"NO"<<endl;
			continue;
		}
		for(int i=0;i<=n;i++){
			pair<int,int> xx;
			if(i<=ind){
				xx={i,ind+1};
			}	
			else{
				xx={ind,i};
			}
			if(xx.a+xx.b==n){
				cout<<"YES"<<endl;
				for(int j=0;j<i;j++){
					cout<<s[j];
				}
				cout<<'a';
				for(int j=i;j<n;j++){
					cout<<s[j];
				}
				cout<<endl;
				break;
			}
		}




	}










 
 
 
	return 0;
}