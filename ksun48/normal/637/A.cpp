#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int z = 0;
int freq[1100000];
int main(){
	for(int i = 0; i < 1100000; i++) freq[i] = 0;
	int n, a;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a;
		freq[a]++;
		if(freq[a] > freq[z]) z = a;
	}
	cout << z << endl;

}