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
	int n;
	string s;
	cin>>n>>s;
	if (n==12){
		if (s[0]>'1'){
			if (s[1]<='2') s[0]='1';
			else s[0]='0';
		}
		if (s[0]=='1'&&s[1]>'2'){
			s[1]='0';
		}
		if (s[0]=='0'&&s[1]=='0') s[1]='1';
	}
	else{
		if (s[0]>'2') s[0]='0';
		if (s[0]=='2'&&s[1]>'3') s[1]='0';
	}
	if (s[3]>'5') s[3]='0';
	cout<<s<<endl;
}