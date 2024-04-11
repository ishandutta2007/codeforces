#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 200000;
int t[maxn];

void add(int t[], int i, int value) {
  for (; i < maxn; i += (i + 1) & -(i + 1))
    t[i] += value;
}

// sum[0..i]
int sum(int t[], int i) {
  if(i < 0) return 0;
  int res = 0;
  for (; i >= 0; i -= (i + 1) & -(i + 1))
    res += t[i];
  return res;
}

int a[200000];

vector<int> pos[110000];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < 200000; i++){
		a[i] = 0;
	}
	for(int i = 0; i < n; i++){
		cin >> a[i];
		pos[a[i]].push_back(i);
	}
	for(int i = 0; i < n; i++){
		add(t, i, 1);
	}
	int prev = -1;
	LL ans = 0;
	for(int i = 0; i < 110000; i++){
		if(pos[i].size() == 0) continue;
		int s = 0;
		for(int j = 0; j < pos[i].size(); j++){
			if(pos[i][j] > prev){
				s = j;
				break;
			}
		}
		for(int j = s; j < pos[i].size(); j++){
			if(pos[i][j] > prev){
				ans += sum(t, pos[i][j])-sum(t,prev);
			} else {
				ans += sum(t, n-1)-sum(t,prev);
				ans += sum(t, pos[i][j])-sum(t,-1);
			}
			prev = pos[i][j];
			add(t,pos[i][j],-1);
		}
		for(int j = 0; j < s; j++){
			if(pos[i][j] > prev){
				ans += sum(t, pos[i][j])-sum(t,prev);
			} else {
				ans += sum(t, n-1)-sum(t,prev);
				ans += sum(t, pos[i][j])-sum(t,-1);
			}
			prev = pos[i][j];
			add(t,pos[i][j],-1);
		}
		//cout << prev << " " << ans << endl;
	}
	cout << ans << endl;
}