//plase fix weird order of queue
//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
 
llo t;
llo aa[1001];
llo bb[1001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		for(int i=0;i<n;i++){
			aa[i]=s[i]-'0';
		//	cin>>aa[i];
		}
		int co=0;
		int co2=0;
		cin>>s;
		for(int i=0;i<n;i++){
			bb[i]=s[i]-'0';
			//cin>>bb[i];
			if(bb[i]>aa[i]){
				co++;
			}
			if(bb[i]<aa[i]){
				co2++;
			}
		}
		if(co>co2){
			cout<<"BLUE"<<endl;
		}
		else if(co2>co){
			cout<<"RED"<<endl;
		}
		else{
			cout<<"EQUAL"<<endl;
		}
	}
 
 
 
 
 
	return 0;
}