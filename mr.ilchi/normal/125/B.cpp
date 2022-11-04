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
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <cstring>
#include <fstream>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef complex<double> point;

string s;

int main(){
	
	ios_base::sync_with_stdio(false);

	cin >> s;

	int b = 0;

	for (int i=0; i<(int)s.size(); ){
		
		int j=i;

		while (s[j]!='>') j++;

		string tmp = s.substr(i,j-i+1); i=j+1; 

		if (tmp[1]=='/'){
			b--;
			for (int z=1; z<=b; z++)
				cout << "  ";
			cout << tmp;
			cout << endl;
		}
		else{
			for (int z=1; z<=b; z++)
				cout << "  " ;
			cout << tmp;
			cout << endl; b++;
		}
	}

	return 0;
}