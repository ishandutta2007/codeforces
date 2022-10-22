#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string s;

int main(void)
{
	cin >> n;
	cin >> s;
	
	int ans = (int)s.size()+1;
	char ans_c[3];
	
	char perm[] = {'B', 'G', 'R'};
	do{
		int cost = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] != perm[i%3]) cost++;
		}
		if(ans > cost){
			ans = cost;
			for(int i = 0; i < 3; i++) ans_c[i] = perm[i];
		}
	}while(next_permutation(perm, perm+3));
	
	cout << ans << endl;
	for(int i = 0; i < s.size(); i++) cout << ans_c[i%3];
	cout << endl;
	
	return 0;
}