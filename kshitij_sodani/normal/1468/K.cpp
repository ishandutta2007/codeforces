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
		//
		cin>>s;
		pair<int,int> ans={0,0};
		for(int i=0;i<s.size();i++){
			pair<int,int> cur={0,0};
			for(int j=0;j<=i;j++){
				if(s[j]=='L'){
					cur.a-=1;
				}
				else if(s[j]=='R'){
					cur.a+=1;
				}
				else if(s[j]=='U'){
					cur.b+=1;
				}
				else{
					cur.b-=1;
				}
			}
			//cout<<cur.a<<":"<<cur.b<<endl;
			pair<int,int> cur2={0,0};
			for(int j=0;j<s.size();j++){
				pair<int,int> prev=cur2;
				if(s[j]=='L'){
					cur2.a-=1;
				}
				else if(s[j]=='R'){
					cur2.a+=1;
				}
				else if(s[j]=='U'){
					cur2.b+=1;
				}
				else{
					cur2.b-=1;
				}
				if(cur2.a==cur.a and cur2.b==cur.b){
					cur2=prev;
				}
			}
			if(cur2.a==0 and cur2.b==0){
				if(cur.a!=0 or cur.b!=0){
					ans={cur.a,cur.b};
				}
			}
		}
		cout<<ans.a<<" "<<ans.b<<endl;

	}


 
	return 0;
}