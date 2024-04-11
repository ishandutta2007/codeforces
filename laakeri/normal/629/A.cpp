#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

string s[111];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>s[i];
	}
	int v=0;
	for (int i=0;i<n;i++){
		int c=0;
		for (int ii=0;ii<n;ii++){
			if (s[i][ii]=='C') c++;
		}
		v+=c*(c-1)/2;
	}
	for (int i=0;i<n;i++){
		int c=0;
		for (int ii=0;ii<n;ii++){
			if (s[ii][i]=='C') c++;
		}
		v+=c*(c-1)/2;
	}
	cout<<v<<endl;
}