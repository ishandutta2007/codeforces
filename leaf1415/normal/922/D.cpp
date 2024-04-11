#include <iostream>
#include <string>
#include <algorithm>
#define llint long long

using namespace std;

struct Str{
	string s;
	llint scnt, hcnt;
	Str(){}
	Str(string a){
		s = a;
		scnt = hcnt = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == 's') scnt++;
			else hcnt++;
		}
	}
	bool operator<(const Str &obj)const{
		if(hcnt == 0) return false;
		if(obj.hcnt == 0) return true;
		double r1 = (double)scnt/hcnt, r2 = (double)obj.scnt/obj.hcnt;
		return r1 < r2;
	}
};

llint n;
string s;
Str t[100005];

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		t[i] = Str(s);
	}
	sort(t, t+n);
	reverse(t, t+n);
	
	string cat;
	for(int i = 0; i < n; i++) cat += t[i].s;
	
	llint ans = 0, scnt = 0;
	for(int i = 0; i < cat.size(); i++){
		if(cat[i] == 's') scnt++;
		else ans += scnt;
	}
	
	cout << ans << endl;
	return 0;
}