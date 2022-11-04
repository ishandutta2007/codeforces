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
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int len;
string s;

int main(){

	cin >> s; len = (int)s.size();

	if (len%2==1) { cout << string(len/2+1,'4') << string(len/2+1,'7') << endl; return 0; }

	bool lucky = true;
	int cnt40=0, cnt70=0;

	for (int i=0; i<(int)s.size(); i++){
		
		if (s[i]!='4' && s[i]!='7'){
			lucky = false;
			break;
		}

		else if (s[i]=='4')
			cnt40++;
		else
			cnt70++;
	}

	if (lucky && cnt40==cnt70) { cout << s << endl; return 0; }

	bool flag = false , bad = false;

	for (int i=1; i<=len/2; i++){
		
		if (s[i-1]>'7') { flag = true; break; }

		else if (s[i-1] < '7') { bad = true; break; }
	}

	if (!flag && !bad){
		
		for (int i=len/2; i<(int)s.size(); i++){

			if (s[i] > '4') { flag=true; break; }

			else if (s[i] < '4') { bad=true; break; }			
		}
	}

	if (flag) { cout << string(len/2 + 1,'4') << string(len/2 + 1,'7') << endl; return 0; }

	int eq=0 , no=-1;
	int eq4=len/2 , eq7=len/2;

	for (int i=0; i<(int)s.size(); i++){
		
		if (eq==-1)
			break;

		if (s[i]<'4'){
			no=i;
			eq=-1;
		}

		else if (s[i]=='4'){

			if (eq7>0) { no = i; }

			if (eq4>0) { eq4--; }

			else { eq=-1; }
		}

		else if (s[i]<'7'){
			
			if (eq7>0) { no = i; }
			
			eq=-1;
		}

		else if (s[i]=='7'){
			
			if (eq7>0) { eq7--; }
			
			else { eq=-1; }
		}

		else if (s[i]>'7') { eq=-1; }
	}

	int res4=len/2 , res7=len/2;

	for (int i=0; i<(int)s.size(); i++){
		
		if (i<no) { cout << s[i]; (s[i]=='4') ? res4-- : res7--; }

		else if (i==no){

			if (s[i]<'4' && res4) { cout << '4'; res4--; }
			
			else { res7--; cout << '7'; }
		}

		else{
			if (res4) { cout << '4'; res4--; }
			else { cout << '7'; res7--; }
		}
	}

	cout << endl;

	return 0;
}