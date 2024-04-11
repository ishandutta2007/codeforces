#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL x, y, m;

void input(){
	cin >> x >> y >> m;
}

int main(){
	input();

	if(x <= 0 && y <= 0){
		if(max(x,y) < m){
			printf("-1\n");
		} else {
			printf("0\n");
		}
		return 0;
	}

	LL numSteps = 0;
	while(max(x,y) < m){
		if(x < y) swap(x,y);
		LL diff = x-y;

		LL nowSteps = (diff)/x + 1;
		numSteps += nowSteps;
		y += nowSteps*x;
	}
	cout << numSteps << endl;
}