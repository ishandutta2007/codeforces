#include <iostream>
#include <set>
#define llint long long

using namespace std;

llint n;
llint a[105];

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	llint min2 = 100, max3 = -1, val;
	for(int i = 0; i < n; i++){
		llint tmp = a[i], cnt2 = 0, cnt3 = 0;
		while(tmp % 3 == 0){
			cnt3++;
			tmp /= 3;
		}
		tmp = a[i];
		while(tmp % 2 == 0){
			cnt2++;
			tmp /= 2;
		}
		if(max3 <= cnt3 && min2 >= cnt2){
			max3 = cnt3, min2 = cnt2, val = a[i];
		}
	}
	
	set<llint> s;
	for(int i = 0; i < n; i++) s.insert(a[i]);
	s.erase(val);
	cout << val << " ";
	
	while(s.size()){
		llint next;
		if(val % 3 == 0 && s.count(val/3)) next = val/3;
		else next = val*2;
		cout << next << " ";
		s.erase(next);
		val = next;
	}
	cout << endl;
		
	return 0;
}