#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int stuff[n];
	for(int i = 0; i < n; i++) cin >> stuff[i];
	// in heap k node a connects to 1+k*a ... k*(a+1)
	int answer[n];
	for(int c = 0; c < n; c++) answer[c] = 0;
	for(int a = 0; a < n; a++){
		//a to start-end
		int cur = 0;
		for(int heap = 1; heap < n; heap++){
			int pstart = 1+(heap-1)*a;
			int pend = (heap-1)*(a+1);
			int nstart = 1+(heap)*a;
			int nend = (heap)*(a+1);
			if(nstart >= n){
				break;
			}
			if(nstart >= (pstart*2 + pend)/3){
				cur = 0;
				for(int i = nstart; (i <= nend) && (i < n); i++){
					if(stuff[a] > stuff[i]){
						cur++;
					}
				}
			} else {
				for(int i = pstart; i < nstart; i++){
					if(stuff[a] > stuff[i]){
						cur--;
					}
				}
				for(int i = pend+1; (i <= nend) && (i < n); i++){
					if(stuff[a] > stuff[i]){
						cur++;
					}
				}
			}

			answer[heap] += cur;
			//cout << a << " " << heap << " " << cur << endl;

		}
	}
	for(int i = 1; i < n; i++){
		cout << answer[i] << " ";
	}
	cout << endl;
}