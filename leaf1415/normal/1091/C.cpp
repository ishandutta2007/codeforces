#include <iostream>
#include <set>
#define llint long long

using namespace std;

llint n;
set<llint> divS, ans;

llint calc(llint x)
{
	llint k = n/x;
	return k*(k-1)/2*x + k;
}

int main(void)
{
	cin >> n;
	
	for(int i = 1; i <= 100000; i++){
		if(n % i == 0) divS.insert(i), divS.insert(n/i);
	}
	
	for(auto it = divS.begin(); it != divS.end(); it++) ans.insert(calc(*it));
	for(auto it = ans.begin(); it != ans.end(); it++) cout << *it << " "; cout << endl;
	return 0;
}