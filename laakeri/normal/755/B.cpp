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
	int n,m;
	cin>>n>>m;
	set<string> h;
	for (int i=0;i<n;i++){
		string s;
		cin>>s;
		h.insert(s);
	}
	int k=0;
	for (int i=0;i<m;i++){
		string s;
		cin>>s;
		if (h.count(s)){
			k++;
		}
	}
	n-=k;
	m-=k;
	n+=k/2+k%2;
	m+=k/2;
	if (n>m){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
}