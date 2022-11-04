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
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

string s;

int main(){
	
	cin >> s;

	int sefr=0 , yek=0 , al=0;

	for (int i=0; i<(int)s.size(); i++){
		if (s[i]=='0')
			sefr++;
		if (s[i]=='1')
			yek++;
		if (s[i]=='?')
			al++;
	}

	int n = (int)s.size();

	int petya = (n-2)/2;
	int masha = n - 2 - petya;

	set <string> sit;

	bool flag = false;

	if (s[n-1]=='?'){
		flag = true;
		al--;
	}

	if (flag){
		s[n-1] = '0';
		sefr++;
	}

	for (int j=0; j<=al; j++){
	
		int t0 = j+sefr;
		int t1 = (al-j)+yek;

		if (masha>=t1)
			sit.insert ("00");

		else if (petya>=t0)
			sit.insert ("11");

		else{
			if (s[n-1]=='0')
				sit.insert ("10");
			else if (s[n-1]=='1')
				sit.insert ("01");
		}
	}

	if (flag){
		s[n-1] = '1';
		sefr--; yek++;
	}

	for (int j=0; j<=al; j++){
	
		int t0 = j+sefr;
		int t1 = (al-j)+yek;

		if (masha>=t1)
			sit.insert ("00");

		else if (petya>=t0)
			sit.insert ("11");

		else{
			if (s[n-1]=='0')
				sit.insert ("10");
			else if (s[n-1]=='1')
				sit.insert ("01");
		}
	}

	for (set <string> :: iterator it = sit.begin(); it!=sit.end(); it++)
		cout << (*it) << endl;

	return 0;
}