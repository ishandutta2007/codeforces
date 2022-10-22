#include <iostream>
#include <string>
#define llint long long

using namespace std;

llint n, k;
string s;
llint Rank[200005];
llint num[200005];

int main(void)
{
	cin >> n >> k;
	cin >> s;
	
	llint h = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '(') Rank[i] = h++;
		else Rank[i] = --h;
	}
	for(int i = 0; i < s.size(); i++) num[Rank[i]]++;
	
	llint bd = -1, rem = 0;
	for(int i = s.size()-1; i >= 0; i--){
		if(k < num[i]){
			bd = i;
			rem = k;
			break;
		}
		k -= num[i]; 
	}
	
	string ans;
	for(int i = 0; i < s.size(); i++){
		if(Rank[i] > bd) ans += s[i];
		if(Rank[i] == bd){
			if(rem > 0) ans += s[i], rem--;
		}
	}
	cout << ans << endl;
	
	return 0;
}