
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
		int n=s.size();
		vector<int> cur;
		for(int i=0;i<n;i++){
			if(cur.size()==0 or s[i]=='A'){
				cur.pb(0);
			}
			else{
				cur.pop_back();
			}
		}
		cout<<cur.size()<<endl;





	}







	return 0;
}