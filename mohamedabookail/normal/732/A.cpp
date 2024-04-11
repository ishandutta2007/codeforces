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
	int a, b; cin >> a >> b;
	int nemo = 1;
	while((a * nemo) % 10 != 0 && (a * nemo) % 10 != b) {
		nemo++;
	}
	cout << nemo << endl;
}