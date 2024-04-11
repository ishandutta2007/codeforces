#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n,a[N],b[N];
int main() {
	int t;cin >> t;
	while(t--) {
		int ok1 = 0,ok2 = 0,ok = 1;
		cin >> n;
		for(int i = 1;i <= n;++i)
			cin >> a[i];
		for(int i = 1;i <= n;++i)
			cin >> b[i];
		for(int i = 1;i <= n;++i){
			if(a[i] != b[i]) {
				if(a[i] > b[i] && !ok2) ok = 0;
				if(a[i] < b[i] && !ok1) ok = 0;
			}
			if(a[i] == 1) ok1 = 1;
			if(a[i] == -1) ok2 = 1;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}