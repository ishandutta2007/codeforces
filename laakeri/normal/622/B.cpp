#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	int t=(s[0]-'0')*10*60+(s[1]-'0')*60+(s[3]-'0')*10+(s[4]-'0');
	int a;
	cin>>a;
	t+=a;
	t%=24*60;
	cout<<t/(10*60);
	t%=(10*60);
	cout<<t/(60);
	t%=(60);
	cout<<":";
	cout<<t/(10);
	t%=(10);
	cout<<t<<endl;
}