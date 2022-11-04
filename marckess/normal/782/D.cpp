#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int, int>
#define vii vector<ii>
#define fi first
#define se second
#define endl '\n'

#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )
#define LSB(S) (S & (-S))

using namespace std;

vb op(1005, false);
int n;
string s1[1005], s2[1005];
set<string> st;
map<string,int> m;
#define nom1(i) s1[i].substr(0,3)
#define nom2(i) s1[i].substr(0,2) + s2[i].substr(0,1)

bool nombrar(){
	map<string, int>::iterator it;

	for(int i = 0; i < n; i++)
		m[nom1(i)]++;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if ( !op[j] ){
				string nom = nom1(j);
				if ( st.find(nom) != st.end() || ( m[nom] > 1 ) ){
					m[nom]--;
					st.insert(nom);
					m[nom2(j)]++;
					op[j] = true;
				}
			}
		}
	}

	for(it = m.begin(); it != m.end(); ++it)
		if ( it->se > 1 )
			return false;

	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> s1[i] >> s2[i];

	if ( nombrar() ){
		cout << "YES" << endl;
		for(int i = 0; i < n; i++){
			if ( op[i] )
				cout << nom2(i);
			else
				cout << nom1(i);
			cout << endl;
		}
	}else
		cout << "NO" << endl;

	return 0;
}