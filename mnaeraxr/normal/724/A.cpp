#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

string s[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int getid(string S){
	for (int i = 0; i < 7; ++i)
		if (S == s[i])
			return i;
	return -1;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s, b;
	cin >> s >> b;

	int id1 = getid(s), id2 = getid(b);

	vector<int> D = {31, 28, 30};

	for (auto d : D){
		if (id2 == (id1 + d) % 7){
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;

	return 0;
}