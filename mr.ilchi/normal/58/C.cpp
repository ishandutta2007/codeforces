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
 *
 *
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXL= 1000*1000+5;

int n;
int cnt[MAXL];

int main (){
	cin >> n;
	for (int i= 1;i<= n;i ++){
		int h;
		cin >> h;
		int val= h-min (i,n-i+1);
		if (val>= 0)
			cnt[val] ++;
	}
	int res= n;
	for (int i= 0;i< MAXL;i ++)
		res= min (res, n-cnt[i]);
	cout << res << endl;

	return 0;
}