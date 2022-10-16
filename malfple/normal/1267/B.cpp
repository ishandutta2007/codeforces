#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	vector<pair<char, int> > vec;
	int cnt = 1;
	for(int i = 1; i < s.length(); ++i){
		if(s[i] != s[i - 1]){
			vec.pb({s[i - 1], cnt});
			cnt = 1;
		}else cnt++;
	}
	vec.pb({s.back(), cnt});
	
	if(vec.size() % 2 != 1)cout << 0 << endl;
	else{
		int mid = vec.size() / 2;
		
		bool ok = true;
		if(vec[mid].S < 2) ok = false;
		
		for(int i = mid - 1, j = mid + 1; i >= 0; --i, j++){
			if(vec[i].F != vec[j].F)ok = false;
			else if(vec[i].S + vec[j].S < 3)ok = false;
		}
		
		if(!ok)cout << 0 << endl;
		else{
			int ans = vec[mid].S + 1;
			
			cout << ans << endl;
		}
	}
	return 0;
}