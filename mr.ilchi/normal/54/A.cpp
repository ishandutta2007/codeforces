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
 *
 *
 */

#include <iostream>

using namespace std;

const int MAXN= 365+5;

bool mark[MAXN];
int n, k, c;

int main (){
	cin >> n >> k >> c;
	for (int i= 1;i<= c;i ++){
		int tmp;
		cin >> tmp;
		mark[tmp]= true;
	}
		
	int res= 0, rem= 0;
	for (int i= 1;i<= n;i ++){
		rem ++;
		if (rem== k || mark[i]){
			rem= 0;
			res ++;
		}
	}
	cout << res << endl;

	return 0;
}