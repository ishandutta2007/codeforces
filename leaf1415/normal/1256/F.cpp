#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;

llint Q;
llint n;
string s, t;

llint get(string &s)
{
	llint ret = 0;
	for(int i = 0; i < s.size(); i++){
		for(int j = 0; j < s.size(); j++){
			if(i >= j) continue;
			if(s[i] > s[j]) ret++;
		}
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q; llint sum;
	for(int q = 0; q < Q; q++){
		cin >> n >> s >> t;
		string S = s, T = t;
		sort(S.begin(), S.end());
		sort(T.begin(), T.end());
		if(S != T){
			cout << "NO" << endl;
			continue;
		}
		for(int i = 1; i < S.size(); i++){
			if(S[i-1] == S[i]){
				cout << "YES" << endl;
				goto end;
			}
		}
		for(int i = 1; i < T.size(); i++){
			if(T[i-1] == T[i]){
				cout << "YES" << endl;
				goto end;
			}
		}
		
		sum = get(s) + get(t);
		if(sum % 2) cout << "NO" << endl;
		else cout << "YES" << endl;
		
		end:;
	}
	
	return 0;
}