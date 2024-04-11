#include<bits/stdc++.h>
using namespace std;
map<string,int> Map1, Map2;
string z[11111];
int main(){
	int n;
	ios::sync_with_stdio(false);
	cin >> n;
	for(int t=0; t<n; t++){
		string s;
		cin >> s;
		z[t] = s;
		int L = s.length();
		bool flag = false;
		set<string> subs;
		for(int i=0; i<L; i++)
		for(int j=1; i+j<=L; j++){
			string sub = s.substr(i,j);
			if(subs.count(sub))continue;
			subs.insert(sub);
			Map1[sub]++;
			Map2[sub] = t;
		}
	}
	for(cin >> n; n --;){
		string s;
		cin >> s;
		if(!Map1.count(s))
			cout << "0 -" << endl;
		else
			cout << Map1[s] << " " << z[Map2[s]] << endl;
	}
	return 0;
}