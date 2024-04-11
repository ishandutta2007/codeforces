#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int v=0;
	int n;
	string s;
	cin>>n>>s;
	for (int i=0;i<n;i++){
		int x=0;
		int y=0;
		for (int ii=i;ii<n;ii++){
			if (s[ii]=='U') y++;
			if (s[ii]=='D') y--;
			if (s[ii]=='L') x--;
			if (s[ii]=='R') x++;
			if (x==0&&y==0) v++;
		}
	}
	cout<<v<<endl;
}