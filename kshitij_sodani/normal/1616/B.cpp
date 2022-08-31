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
		int n;
		cin>>n;
		string s;
		cin>>s;
		int ind=0;
		for(int i=1;i<n;i++){
			int xx=0;
			if(i==1){
				xx=1;
			}
			if((s[i]-'a')<=(s[i-1]-'a')-xx){
				ind++;
			}
			else{
				break;
			}
		}
		
		for(int i=0;i<=ind;i++){
			cout<<s[i];
		}
		for(int i=ind;i>=0;i--){
			cout<<s[i];
		}
		cout<<endl;
	}






 
	return 0;
}