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
		int ba=-1;
		for(int i=0;i<n;i++){
			int x=s[i]-'0';
			for(int j=1;j>=0;j--){
				if(j+x!=ba){
					cout<<j;
					ba=j+x;
					break;
				}
			}
		/*	if(i%2==0){
				
				cout<<min(2-x,1);
			}
			else{
				cout<<1-x;
			}*/
		}
		cout<<endl;
	}





	
 
	return 0;
}