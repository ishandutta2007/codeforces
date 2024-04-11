#include <bits/stdc++.h>
using namespace std;
bool judge(string s,string t,int n,int m){
	int i=n,j=m;
	for (;j>=1 && i>=1;){
		if (s[i]==t[j]){
			i--;
			j--;	
		}
		else{
			for (int k=1;k<j;k++) if (s[i]==t[k]) return false;
			i--;	
		}
	}
	if (j>=1) return false;
	return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (;T--;){
		string s,t;
		cin >> s >> t;
		int n=s.length();
		int m=t.length();
		s=" "+s;
		t=" "+t;
		if (judge(s,t,n,m))	cout << "YES" << "\n";
		else cout << "NO" << "\n"; 
	}
	return 0;	
}