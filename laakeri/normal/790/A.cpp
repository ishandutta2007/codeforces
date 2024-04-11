#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

string sn[55];

string gn(int i){
	if (i<26){
		char lol='A'+i;
		string x="";
		x+=lol;
		return x;
	}
	else{
		char lol='a'+(i-26);
		string x="A";
		x+=lol;
		return x;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for (int i=0;i<k-1;i++){
		sn[i]=gn(i);
	}
	for (int i=k-1;i<n;i++){
		string s;
		cin>>s;
		if (s=="NO"){
			sn[i]=sn[i-k+1];
		}
		else{
			sn[i]=gn(i);
		}
	}
	for (int i=0;i<n;i++){
		cout<<sn[i]<<" ";
	}
}