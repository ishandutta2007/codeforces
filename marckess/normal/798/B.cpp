#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vb vector<bool>
#define ii pair<int, int>
#define vii vector<ii>

#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )

using namespace std;


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	string s[52];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> s[i];

	int res = 1e9; bool pos = false;
	for(int i = 0; i < n; i++){
		int c = 0;
		int sum = 0;
		for(int j = 0; j < n; j++){
			if ( i != j ){
				for(int k = 0; k < s[0].size(); k++){
					bool igual = true;
					for(int l = 0; l < s[0].size(); l++){
						if ( s[i][l] != s[j][ (k+l) % s[0].size() ] ){
							igual = false;
							break;
						}
					}
					if ( igual ){
						sum += k;
						c++;
						break;
					}
				}
			}
		}
		if ( c == n - 1 ){
			pos = true;
			res = min(res, sum);
		}
	}

	if ( pos )
		cout << res;
	else
		cout << -1;

	return 0;
}