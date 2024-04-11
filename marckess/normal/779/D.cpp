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

using namespace std;

string t, p;
int a[200002], v[2000002], b, x;

bool isPos(int m){
	int i = 0, j = 0;
	for(; i < t.size() && j < p.size(); i++ ){
		if ( t[i] == p[j] && v[i+1] > m )
			j++;
	}
	return j == p.size();
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t >> p;

	for(int i = 1; i <= t.size(); i++){
		cin >> x;
		v[x] = i;
	}

	int i = 0, j = t.size(), m = (i+j)/2;

	for(int k = 0; k < 30; k++){
		if ( isPos(m) )
			i = m;
		else
			j = m;
		m = (i+j)/2;
	}

	cout << m;

	return 0;
}