#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};
map<int, map<int,int> > freq;
int ans = 0;
void add(int x, int y){
	ans++;
	for(int i = 0; i < 8; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		freq[nx][ny]++;
		if(freq[nx][ny] == 4) add(nx, ny);
	}
}
void test(int n, int t){
	freq.clear();
	ans = 0;
	int l = n/3;
	vector<int> xl;
	vector<int> yl;
	for(int i = 0; i < l; i++){
		xl.push_back(2*i);
		yl.push_back(0);
		xl.push_back(2*i+1);
		yl.push_back(1);
		xl.push_back(2*i);
		yl.push_back(2);
	}
	int rem = n-l-l;
	for(int i = 0; i < rem; i++){
		if(i % 2){
			xl.push_back(0);
			yl.push_back(3 + i/2);
		} else {
			xl.push_back(l-1);
			yl.push_back(3 + i/2);			
		}
	}
	for(int i = 0; i < n; i++){
		if(t == 0){
			cout << xl[i] << " " << yl[i] << '\n';
		} else if(t == 1){
			freq[xl[i]][yl[i]] = 8;
		}
	}
	for(int i = 0; i < n; i++){
		add(xl[i], yl[i]);
	}
	assert(ans >= n*n/10);
}
int main(){
	/*test(1000,1);
	for(int i = 1; i <= 1000; i += 2){
		test(i, 1);
		cout << i << endl;
	}*/
	int n;
	cin >> n;
	test(n, 0);
}