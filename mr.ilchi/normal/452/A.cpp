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
#include <fstream> 
#include <sstream> 
#include <cstdio> 
#include <cstring> 
#include <cstdlib> 
#include <cmath> 
#include <ctime> 
#include <algorithm> 
#include <vector> 
#include <queue> 
#include <deque> 
#include <stack> 
#include <set> 
#include <map> 
#include <complex> 
#include <bitset> 
#include <iomanip> 
#include <utility> 

using namespace std;

string a[] = {"Vaporeon", "Jolteon", "Flareon", "Espeon", "Umbreon", "Leafeon", "Glaceon", "Sylveon"};

int main(){
	int temp; cin >> temp;
	string s; cin >> s;
	for (int i=0; true; i++){
		if (a[i].size() == s.size()){
			bool f = true;
			for (int j=0; j<(int)a[i].size(); j++)
				if (s[j]!='.' && s[j]!=tolower(a[i][j]))
					f = false;
			if (f){
				a[i][0] = tolower(a[i][0]);
				cout << a[i] << endl;
				break;
			}
		}
	}
	return 0;
}