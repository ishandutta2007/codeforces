#include <iostream>
#include <vector>

using namespace std;

int h1, a1, c1;
int h2, a2;
vector<int> act;

int main(void)
{
	cin >> h1 >> a1 >> c1;
	cin >> h2 >> a2;
	
	while(1){
		if(a1 >= h2){
			act.push_back(1);
			h2 -= a1;
		}
		else if(a2 >= h1){
			act.push_back(0);
			h1 += c1;
		}
		else{
			act.push_back(1);
			h2 -= a1;
		}
		if(h2 <= 0) break;
		h1 -= a2;
	}
	
	cout << act.size() << endl;
	for(int i = 0; i < act.size(); i++){
		if(act[i]) cout << "STRIKE" << endl;
		else cout << "HEAL" << endl;
	}
	return 0;
}