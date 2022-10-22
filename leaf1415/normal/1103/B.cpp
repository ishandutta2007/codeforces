#include <iostream>
#include <string>
#define llint long long

using namespace std;

string s, res;

int main(void)
{
	while(1){
		cin >> s;
		if(s == "mistake" || s == "end") break;
		
		llint l = 0, r = 1;
		while(1){
			cout << "? " << l << " " << r << endl;
			cin >> res;
			if(res == "x") break;
			l = r, r = r*2+1;
		}
		
		llint ub = r, lb = l, mid;
		while(ub - lb > 1){
			mid = (ub + lb) / 2;
			cout << "? " << l << " " << mid << endl;
			cin >> res;
			if(res == "x") ub = mid;
			else lb = mid;
		}
		cout << "! " << ub << endl;
	}
	return 0;
}