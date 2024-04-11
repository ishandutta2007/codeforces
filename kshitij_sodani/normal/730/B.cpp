//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
bool ask(int x,int y){
	cout<<"? "<<x+1<<" "<<y+1<<endl;
	string s;
	cin>>s;
	if(s=="<" or s=="="){
		return true;
	}
	return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==1){
			cout<<"! "<<1<<" "<<1<<endl;
			continue;
		}
		
		vector<int> pp;
		vector<int> tt;
		for(int i=0;i<n;i+=2){
			if(i==n-1){
				pp.pb(i);
				tt.pb(i);
			}
			else{
				if(ask(i,i+1)){
					pp.pb(i);
					tt.pb(i+1);
				}
				else{
					pp.pb(i+1);
					tt.pb(i);
				}
			}
		}
		while(pp.size()>1){
			int x=pp[pp.size()-2];
			int y=pp.back();
			pp.pop_back();
			pp.pop_back();
			if(ask(x,y)){
				pp.pb(x);
			}
			else{
				pp.pb(y);
			}
		}
		while(tt.size()>1){
			int x=tt[tt.size()-2];
			int y=tt.back();
			tt.pop_back();
			tt.pop_back();
			if(ask(x,y)){
				tt.pb(y);
			}
			else{
				tt.pb(x);
			}
		}
		cout<<"! "<<pp[0]+1<<" "<<tt[0]+1<<endl;


	}




 
 
	return 0;
}