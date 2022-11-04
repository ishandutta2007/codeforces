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

typedef long long LL;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;

string name[] = {
"Washington", 
"Adams", 
"Jefferson", 
"Madison", 
"Monroe", 
"Adams", 
"Jackson", 
"Van Buren", 
"Harrison", 
"Tyler", 
"Polk", 
"Taylor", 
"Fillmore", 
"Pierce", 
"Buchanan", 
"Lincoln", 
"Johnson", 
"Grant", 
"Hayes", 
"Garfield", 
"Arthur", 
"Cleveland", 
"Harrison", 
"Cleveland", 
"McKinley", 
"Roosevelt", 
"Taft", 
"Wilson", 
"Harding", 
"Coolidge", 
"Hoover", 
"Roosevelt", 
"Truman", 
"Eisenhower", 
"Kennedy", 
"Johnson", 
"Nixon", 
"Ford", 
"Carter", 
"Reagan", 
"Bush", 
"Clinton", 
"Bush", 
"Obama", 	
};


int main(){
/*	string s;
	while (getline(cin,s)){
		istringstream inp(s);
		string t; inp >> t >> t;
		while (t[(int)t.size()-1]!=','){
			string temp; inp >> temp;
			t+= " " + temp;
		}
		t = t.substr(0, t.size()-1);
		cout << "\"" << t << "\", " << endl;
	}*/
	int x; cin >> x; cout << name[x-1] << endl;
	return 0;
}