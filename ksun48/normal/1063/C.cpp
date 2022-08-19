#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int pr(LL a){
	cout << a/2 << " " << (a+1) / 2 << endl;
	fflush(stdout);
	string ans;
	cin >> ans;
	return ans == "white";
}

int main(){
	int n;
	cin >> n;
	LL bcur = 6;
	LL wcur = 2000000000 - 6;
	for(int i = 0; i < n; i++){
		LL m = (bcur + wcur) / 2;
		if(pr(m)){
			wcur = m;
		} else {
			bcur = m;
		}
		assert(bcur < wcur);
	}
	wcur = bcur + 1;
	if(bcur % 2 == 0){
		cout << bcur/2 + 1 << " " << bcur/2 << " " << bcur/2 - 1 << " " << bcur/2 + 1 << endl;
	} else if(bcur % 2 == 1){
		cout << bcur/2 + 1 << " " << bcur/2 << " " << bcur/2 << " " << bcur/2 + 2 << endl;		
	}
	return 0;
}