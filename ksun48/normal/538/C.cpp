#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int ab(int a){
	if(a < 0) return -a;
	return a;
}

int main(){
	int n, m;
	cin >> n >> m;
	int maxh = 0;
	int a[m];
	int b[m];
	for(int i = 0; i < m; i++) cin >> a[i] >> b[i];
	for(int i = 0; i < m-1; i++){
		if(ab(b[i]-b[i+1]) > ab(a[i]-a[i+1])){
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
		maxh = max(maxh, max(b[i],b[i+1])+(ab(a[i]-a[i+1])-ab(b[i]-b[i+1]))/2);
	}
	maxh = max(maxh, b[0]+a[0]-1);
	maxh = max(maxh, b[m-1]+n-a[m-1]);
	cout << maxh << endl;

}