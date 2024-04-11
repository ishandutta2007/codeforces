#include <iostream>
#include <stdio.h>

using namespace std;

int m, n;
int valid[35];

int main(void)
{
	cin >> m >> n;
	for(int i = 0; i < n; i++){
		cout << 1 << endl; fflush(stdout);
		cin >> valid[i];
		if(valid[i] == 0 || valid[i] == -2) return 0;
	}
	
	int res, id = 0;
	int ub = m+1, lb = 1, mid;
	while(ub - lb > 1){
		mid = (ub + lb) / 2;
		cout << mid << endl; fflush(stdout);
		cin >> res;
		if(res == 0 || res == -2) return 0;
		res *= valid[id % n];
		id++;
		if(res == 1) lb = mid;
		if(res == -1) ub = mid;
	}
	return 0;
}