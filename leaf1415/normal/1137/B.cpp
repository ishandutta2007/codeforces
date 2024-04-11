#include <iostream>
#include <string>

using namespace std;

string s, t;
int cnt0, cnt1;
int need0, need1, add0, add1;
int z[500005];

void z_algorithm(string s, int z[])
{
	z[0] = s.size();
	
	int x = 0, y = 0;
	for(int i = 1; i < s.size(); i++){
		if(i > y){
			z[i] = 0;
			for(int j = 0; j < s.size(); j++){
				if(i+j > s.size() || s[i+j] != s[j]) break;
				z[i]++;
			}
			x = i, y = i + z[i] - 1;
		}
		else if(i + z[i-x] <= y) z[i] = z[i-x];
		else{
			z[i] = y-i+1;
			for(int j = y-i+1; j < s.size(); j++){
				if(i+j > s.size() || s[i+j] != s[j]) break;
				z[i]++;
			}
			x = i, y = i + z[i] - 1;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s >> t;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '0') cnt0++;
		else cnt1++;
	}
	
	z_algorithm(t, z);
	
	int len = 0;
	for(int i = 1; i < t.size(); i++){
		if(i + z[i] >= t.size()){
			len = z[i];
			break;
		}
	}
	string u = t.substr(len);
	
	for(int i = 0; i < t.size(); i++){
		if(t[i] == '0') need0++;
		else need1++;
	}
	for(int i = 0; i < u.size(); i++){
		if(u[i] == '0') add0++;
		else add1++;
	}
	
	//cout << u << endl;
	
	string ans;
	if(cnt0 >= need0 && cnt1 >= need1){
		ans += t;
		cnt0 -= need0, cnt1 -= need1;
	}else{
		for(int i = 0; i < cnt0; i++) ans += '0';
		for(int i = 0; i < cnt1; i++) ans += '1';
		cout << ans << endl;
		return 0;
	}
	
	while(cnt0 >= add0 & cnt1 >= add1){
		ans += u;
		cnt0 -= add0, cnt1 -= add1;
	}
	for(int i = 0; i < cnt0; i++) ans += '0';
	for(int i = 0; i < cnt1; i++) ans += '1';
	
	cout << ans << endl;
	
	return 0;
}