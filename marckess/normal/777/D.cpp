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

string s[500005];
vi mx(500005);

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s[i];
		mx[i] = s[i].size();
	}

	for(int i = n - 2; i >= 0; i--){
		int j = i + 1, mn = min(mx[j], mx[i]);
		int l;
		for(l = 1; l < mn; l++){
			if ( s[i][l] != s[j][l] ){
				if ( s[i][l] > s[j][l] )
					mx[i] = l;
				break;
			}
		}
		if ( l == mn && mx[i] > mx[j] )
			mx[i] = mx[j];
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < mx[i]; j++)
			cout << s[i][j];
		cout << endl;
	}

	return 0;
}