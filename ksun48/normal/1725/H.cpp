#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N;
	cin >> N;
	vector<int> A(N);
	for(int& x : A) cin >> x;
	vector<vector<int> > which(2);
	for(int i = 0; i < N; i++){
		if(A[i] % 3 == 0){
			which[0].push_back(i);
		} else {
			which[1].push_back(i);
		}
	}
	int Z;
	int idx;
	if(which[0].size() >= which[1].size()){
		Z = 2;
		idx = 1;
	} else {
		Z = 0;
		idx = 0;
	}
	string S(N, '1');
	int cnt = N / 2;
	for(int x : which[idx]){
		S[x] = '0';
		cnt--;
	}
	for(int x : which[1^idx]){
		if(cnt){
			S[x] = '0';
			cnt--;
		}
	}
	cout << Z << '\n';
	cout << S << '\n';
}