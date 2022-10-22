#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
string s, t;
queue<int> q[26];
int a[55];
vector<int> ans;

int main(void)
{
	cin >> n;
	cin >> s >> t;
	
	string S = s, T = t;
	sort(S.begin(), S.end());
	sort(T.begin(), T.end());
	if(S != T){
		cout << -1 << endl;
		return 0;
	}
	
	for(int i = 0; i < t.size(); i++){
		q[t[i]-'a'].push(i);
	}
	for(int i = 0; i < s.size(); i++){
		a[i] = q[s[i]-'a'].front();
		q[s[i]-'a'].pop();
	}
	
	for(int i = 0; i < s.size(); i++){
		for(int j = 0; j < s.size()-1; j++){
			if(a[j] > a[j+1]){
				ans.push_back(j);
				int t = a[j];
				a[j] = a[j+1]; a[j+1] = t;
			}
		}
	}
	
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) cout << ans[i]+1 << " ";
	cout << endl;
	
	return 0;
}