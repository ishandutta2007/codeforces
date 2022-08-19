#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	int n, k, x;
	cin >> n >> k >> x;
	LL freq[1024];
	for(int i = 0; i < 1024; i++) freq[i] = 0;
	for(int i = 0; i < n; i++){
		int c;
		cin >> c;
		freq[c]++;
	}
	for(int i = 0; i < k; i++){
		LL newfreq[1024];
		for(int i = 0; i < 1024; i++) newfreq[i] = 0;
		LL p = 1;
		for(int i = 0; i < 1024; i++){
			newfreq[i] += freq[i] / 2;
			newfreq[i ^ x] += freq[i] / 2;
			freq[i] %= 2;
			if(freq[i]){
				if(p){
					newfreq[i^x] ++;
				} else {
					newfreq[i] ++;
				}
			}
			p += freq[i];
			p %= 2;
			freq[i] = 0;
		}
		for(int i = 0; i < 1024; i++){
			freq[i] = newfreq[i];
		}
	}
	for(int i = 1023; i >= 0; i--){
		if(freq[i] > 0){
			cout << i << " ";
			break;
		}
	}
	for(int i = 0; i < 1024; i++){
		if(freq[i] > 0){
			cout << i << endl;
			break;
		}
	}	
}