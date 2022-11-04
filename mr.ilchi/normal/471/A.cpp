#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> q;
	int t; while (cin >> t) q.push_back(t);
	vector<int> rem;
	for (int i=0; i<(int)q.size(); i++){
		int cnt = 0;
		for (int j=0; j<(int)q.size(); j++) 
			cnt+= q[i] == q[j];
		if (cnt >= 4){
			cnt = min(cnt,4);
			for (int j=0; j<(int)q.size(); j++){
				if (q[i]!=q[j] || cnt==0)
					rem.push_back(q[j]);
				cnt-= q[i] == q[j];
			}
		}
	}
	if (rem.empty()){
		cout << "Alien" << endl;
		return 0;
	}
	if (rem[0] != rem[1])
		cout << "Bear" << endl;
	else
		cout << "Elephant" << endl;
	return 0;
}