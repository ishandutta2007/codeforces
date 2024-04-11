#include <iostream>
#include <time.h>
#include <stdlib.h>
#define llint long long

using namespace std;

llint n, k;

int main(void)
{
	cin >> n >> k;
	srand(time(NULL));
	
	string res;
	llint ub = n+1, lb = 1, mid;
	while(1){
		if(ub - lb > 50){
			mid = (ub + lb) / 2;
			cout << mid << " " << ub-1 << endl;
			cin >> res;
			if(res == "Bad") return 0;
			if(res == "Yes") lb = mid;
			else ub = mid;
		}
		else{
			llint L = ub - lb;
			llint p = rand() % L + lb;
			cout << p << " " << p << endl;
			cin >> res;
			if(res == "Bad" || res == "Yes") return 0;
		}
		ub = min(ub+k, n+1);
		lb = max(lb-k, 1LL);
	}
	
	return 0;
}