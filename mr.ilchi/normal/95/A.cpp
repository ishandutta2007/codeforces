/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxN = 100 + 5;

bool mark[maxN];
int n;
string s,M;
set <string> sit;

int main(){

	cin >> n;
	for (int i=1;i<=n;i++){

		string bad;
		cin >> bad;
		for (int j=0; j<(int)bad.size(); j++) if (bad[j]<='Z' && bad[j]>='A')
			bad[j] = bad[j] -'A' + 'a';
		sit.insert (bad);
	}

	cin >> s;
	
	M = s;

	for (int i=0; i<(int)M.size(); i++)
		if (M[i]>='A' && M[i]<='Z')
			M[i] = M[i] - 'A' + 'a';

	for (int i=0; i<(int)M.size(); i++){
		for (int j=(int)M.size()-1; j>=i; j--){
			if (sit.find (M.substr (i,j-i+1))!=sit.end()){
				for (int z=i; z<=j; z++)
					mark[z] = true;
				break;				
			}
		}
	}

	char luck; cin >> luck;
	char LUCK = luck-'a'+'A';

	for (int i=0; i<(int)s.size(); i++){
		
		if (mark[i]){

			if (s[i]>='A' && s[i]<='Z'){
				
				if (s[i]==LUCK)
					s[i] = (LUCK=='A') ? 'B' : 'A';

				else
					s[i] = LUCK;
			}

			else{
				
				if (s[i]==luck)
					s[i] = (luck=='a') ? 'b' : 'a';
				else
					s[i] = luck;
			}
		}

		cout << s[i];
	}

	cout << endl;

	return 0;
}