#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	vector<int> ans;
	for(int p = 2; p <= n; p++){
		int pr = 1;
		for(int i = 2; i*i <= p; i++){
			if(p % i == 0) pr = 0;
		}
		if(pr){
			int c = p;
			while(c <= n){
				ans.push_back(c);
				c *= p;
			}
		}

	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << endl;

}