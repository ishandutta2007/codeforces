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
		for(int i=n-1;i>=0;i--){
			if(s[i]==')'){
				co++;
			}
			else{
				break;
			}
		}
		if(co>n-co){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}

 
	return 0;
}