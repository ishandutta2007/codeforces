#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int can[101010][2];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	int n=s.size();
	can[n][0]=1;
	set<string> v;
	for (int i=n-1;i>=5;i--){
		if (can[i+2][0]==1){
			if (i+3<n){
				if (!(s[i]==s[i+2]&&s[i+1]==s[i+3])){
					can[i][0]=1;
				}
			}
			else{
				can[i][0]=1;
			}
		}
		if (can[i+2][1]==1){
			can[i][0]=1;
		}
		if (can[i+3][0]==1){
			can[i][1]=1;
		}
		if (can[i+3][1]==1){
			if (i+5<n){
				if (!(s[i]==s[i+3]&&s[i+1]==s[i+4]&&s[i+2]==s[i+5])){
					can[i][1]=1;
				}
			}
			else{
				can[i][0]=1;
			}
		}
		if (can[i][0]==1){
			string t;
			t+=s[i];
			t+=s[i+1];
			v.insert(t);
		}
		if (can[i][1]==1){
			string t;
			t+=s[i];
			t+=s[i+1];
			t+=s[i+2];
			v.insert(t);
		}
	}
	cout<<v.size()<<endl;
	for (auto t:v){
		cout<<t<<'\n';
	}
}