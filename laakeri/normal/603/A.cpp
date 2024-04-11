#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	int v=0;
	int t='.';
	for (int i=0;i<n;i++){
		if (s[i]!=t){
			v++;
			t=s[i];
		}
	}
	for (int i=1;i<n-1;i++){
		if (s[i]==s[i-1]&&s[i]==s[i+1]){
			cout<<v+2<<endl;
			return 0;
		}
	}
	int f=0;
	for (int i=1;i<n;i++){
		if (s[i]==s[i-1]){
			if (f>0){
				cout<<v+2<<endl;
				return 0;
			}
			f=1;
		}
	}
	for (int i=1;i<n;i++){
		if (s[i]==s[i-1]){
			cout<<v+1<<endl;
			return 0;
		}
	}
	cout<<v<<endl;
}