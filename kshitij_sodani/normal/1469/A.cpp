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
		int cur=0;
		int cur2=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='('){
				cur=i;
			}
			if(s[i]==')'){
				cur2=i;
			}
		}
		if(s.size()%2==1 or cur2==0 or cur==s.size()-1){
			cout<<"NO"<<endl;
			continue;
		}
		else{
			cout<<"YES"<<endl;
			continue;
		}
		if(cur<cur2){
			if((cur2-cur)%2==1 and cur%2==0){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}
		else{
			if(cur2%2==1 and cur%2==0){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}

		}
		



	}





	return 0;
}