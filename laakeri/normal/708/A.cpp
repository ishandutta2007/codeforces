#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	int na=0;
	for (int i=0;i<(int)s.size();i++){
		if (s[i]!='a') na=1;
	}
	if (na==0){
		s.back()='z';
		cout<<s<<endl;
		return 0;
	}
	int f=0;
	for (int i=0;i<(int)s.size();i++){
		if (s[i]!='a'){
			f=1;
		}
		if (f){
			if (s[i]=='a') break;
			s[i]--;
		}
	}
	cout<<s<<endl;
}