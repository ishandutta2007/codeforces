#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, m;
	cin >> n >> m;
	int wgt[n];
	for(int i = 0; i < n; i++){
		cin >> wgt[i];
	}
	int b[m];
	for(int i = 0; i < m; i++){
		cin >> b[i];
		b[i]--;
	}
	int stuff[n];
	int numbooks = 0;
	int answer = 0;
	for(int i = 0; i < m; i++){
		int yes = 0;
		for(int j = 0; j < numbooks; j++){
			if(stuff[j] == b[i]){
				for(int k = j-1; k >= 0; k--){
					stuff[k+1] = stuff[k];
					answer += wgt[stuff[k]];
				}
				stuff[0] = b[i];
				yes = 1;
				break;
			}
		}
		if(yes == 0){
			stuff[numbooks] = b[i];
			numbooks++;
			for(int k = numbooks-2; k >= 0; k--){
				stuff[k+1] = stuff[k];
				answer += wgt[stuff[k]];
			}
			stuff[0] = b[i];
		}
		//cout << answer << endl;

	}
	cout << answer << endl;

}