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
	llo t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		string t;
		cin>>t;
		if(false){//t[t.size()-1]!=s[s.size()-1]){
			cout<<"NO"<<endl;
		}
		else{
			llo ind=t.size()-1;
			//ind--;
			llo ind2=s.size()-1;
			//ind2--;
			int xx=(s.size()%2);//(s.size()-1)%2;
			while(ind2>=0 and ind>=0){
				if(t[ind]==s[ind2] and (ind2%2)!=xx){
					xx=(ind2%2);
					ind--;
				}
				ind2-=1;
			}
			if(ind<0){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}
	}
 
 

 
 
 
	return 0;
}