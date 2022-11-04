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
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxW= 1000 + 5;

int n,m,waste,Q;
int x[maxW], y[maxW];

inline void check (int row, int col){

	int cnt= (row-1)*m + col-1;

	for (int i=1;i<=waste;i++){
		if (x[i]==row && y[i]==col){
			cout << "Waste" << endl;
			return;
		}

		if ((x[i]<row) || ((x[i]==row) && (y[i]<col)))
			cnt--;
	}

	cnt%=3;

	if (cnt==0){
		cout << "Carrots" << endl;
		return;
	}

	if (cnt==1){
		cout << "Kiwis" << endl;
		return;
	}

	cout << "Grapes" << endl;
}
/******************************************/
int main(){

	cin >> n >> m >> waste >> Q;

	for (int i=1;i<=waste;i++){
		cin >> x[i] >> y[i];
	}

	while (Q){
		
		int xx, yy;
		cin >> xx >> yy;

		check (xx,yy);

		Q--;
	}

	return 0;
}