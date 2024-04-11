#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int, int>
#define vii vector<ii>

using namespace std;

string s;

int main(){
	vi cubeta(30,0);
	stack<char> st;

	cin >> s;

	for(int i = 0; i < s.size(); i++)
		cubeta[s[i] - 'a']++;

	int j = 0;
	while(cubeta[j] == 0)
		j++;

	for(int i = 0; i < s.size(); i++ ){
		if ( s[i] - 'a' == j ){
			cout << s[i];
			cubeta[j]--;
			while( j < 30 && cubeta[j] == 0 )
				j++;
			while ( st.size() && st.top() - 'a' <= j ){
				cout << st.top();
				st.pop();
			}
		}else{
			st.push(s[i]);
			cubeta[s[i]-'a']--;
		}
	}

	while(st.size()){
		cout << st.top();
		st.pop();
	}

	return 0;
}