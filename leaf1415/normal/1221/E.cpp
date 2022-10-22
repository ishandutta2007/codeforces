#include <iostream>
#include <string>
#include <vector>
#define llint long long

using namespace std;

llint Q;
llint a, b;
string s;
vector<llint> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> a >> b;
		cin >> s;
		s += "X";
		
		vec.clear();
		llint cnt = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '.') cnt++;
			else{
				if(cnt >= b) vec.push_back(cnt);
				cnt = 0;
			}
		}
		bool overA = false, onlyB = false;
		llint cnt2B = 0, len2B, cntA2B = 0;
		for(int i = 0; i < vec.size(); i++){
			if(vec[i] >= a) overA = true;
			if(vec[i] < a && vec[i] >= b) onlyB = true;
			if(vec[i] >= 2*b) cnt2B++, len2B = vec[i];
			if(vec[i] >= a && vec[i] < 2*b) cntA2B++;
		}
		if(!overA || onlyB || cnt2B >= 2){
			cout << "NO" << "\n";
			continue;
		}
		//cout << cnt2B << " " << len2B << " " << cntA2B << endl;
		if(cnt2B == 1){
			bool flag = false;
			for(int i = 0; i <= len2B-a; i++){
				llint l = i, r = len2B-(i+a);
				if(l >= 2*b || r >= 2*b) continue;
				if((b <= l && l < a) || (b <= r && r < a)) continue;
				llint num = 0;
				if(l >= a && l < 2*b) num++;
				if(r >= a && r < 2*b) num++;
				if((cntA2B + num) % 2 == 0) flag = true;
			}
			if(flag) cout << "YES" << "\n";
			else cout << "NO" << "\n";
			continue;
		}
		if(cntA2B % 2) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	flush(cout);
	
	return 0;
}