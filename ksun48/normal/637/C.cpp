#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int r = 6;
	int n;
	cin >> n;
	string a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			int z = 0;
			for(int k = 0; k < 6; k++){
				if(a[i][k] != a[j][k]) z++;
			}
			r = min(r,(z-1)/2);
		}
	}
	cout << r << endl;
}