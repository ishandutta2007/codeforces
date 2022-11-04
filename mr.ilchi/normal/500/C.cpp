#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000+10;

bool mark[MAXN];
int n,m;
int w[MAXN],b[MAXN];

int main(){
	cin >> n >> m;
	for (int i=0; i<n; i++) cin >> w[i];
	for (int i=0; i<m; i++) { cin >> b[i]; b[i]--; }
	long long ans = 0;
	for (int i=0; i<m; i++){
		memset(mark, false, sizeof mark);
		for (int j=i-1; j>=0; j--){
			if (b[i] == b[j]) break;
			if (!mark[b[j]])
				ans+= w[b[j]];
			mark[b[j]] = true;
		}
	}
	cout << ans << endl;
	return 0;
}