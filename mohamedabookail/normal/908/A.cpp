/**
 *    author:  Mohamed Abo_Okail
 *    created: 22/O1/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define ll long long
#define endl "\n"
 
int main() 
{
	std::ios_base::sync_with_stdio(0);
	string s; cin >> s;
	int ar[] = {'a', 'e', 'i', 'o', 'u', '1', '3', '5', '7', '9'};
	int nemo = 0;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < 10; j++) {
			if(s[i] == ar[j]) {
				nemo++;
			}
		}
	}
	cout << nemo << endl;
}