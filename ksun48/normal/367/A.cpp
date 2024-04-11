#include<iostream>
using namespace std;
typedef long long LL;

int main(){
	string s;
	cin >> s;
	int xsums[s.size()];
	int ysums[s.size()];
	int zsums[s.size()];
	xsums[0] = ysums[0] = zsums[0] = 0;
	for(int i = 0; i < s.size(); i++){
		xsums[i+1] = xsums[i];
		ysums[i+1] = ysums[i];
		zsums[i+1] = zsums[i];
		if(s[i] == 'x'){
			xsums[i+1]++;
		} else if(s[i] == 'y'){
			ysums[i+1]++;
		} else if(s[i] == 'z'){
			zsums[i+1]++;
		}
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; i++){
		int l, r;
		cin >> l >> r;
		if(r-l <= 1){
			cout << "YES" << endl;
			continue;
		}
		int x = xsums[r]-xsums[l-1];
		int y = ysums[r]-ysums[l-1];
		int z = zsums[r]-zsums[l-1];
		if(max(max(x,y),z) - min(min(x,y),z) <= 1){
			cout << "YES" << endl;
		} else{
			cout << "NO" << endl;
		}
	}
}