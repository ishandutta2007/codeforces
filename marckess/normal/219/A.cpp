#include <bits/stdc++.h>

using namespace std;

int main(){
	int k;
	vector<int> v(27,0);
	string s;
	cin >> k >> s;

	for(int i = 0; i< s.size(); i++)
		v[s[i]-'a'] ++;

	bool f = false;
	for(int i = 0; i < 'z'-'a'+1; i++){
		if ( v[i] % k )
			f = true;
	}

	if ( f ){
		cout << -1;
		return 0;
	}

	string ss = "";
	for(int i = 0; i<'z'-'a'+1; i++){
		for(int j = 0; j < v[i] / k; j++)
			ss += 'a' + i;
	}

	while(k--)
		cout << ss;

	return 0;
}