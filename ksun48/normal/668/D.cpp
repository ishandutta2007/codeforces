#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define LOGSZ 22
vector<int> a[1100000];
vector<int> t[1100000];
vector<int> idxans[1100000];
int sorted[1100000];
int ans[1100000];

int tree[(1<<LOGSZ)+1];
int N = (1<<LOGSZ);

// add v to value at x
void set1(int x, int v) {
  while(x <= N) {
    tree[x] += v;
    x += (x & -x);
  }
}

// get cumulative sum up to and including x
int get(int x) {
  int res = 0;
  while(x) {
    res += tree[x];
    x -= (x & -x);
  }
  return res;
}


int main(){
	map<int,int> x2i;
	int n;
	scanf("%d", &n);
	int x[n];
	for(int i = 0; i < n; i++){
		ans[i] = -1;
		int b, c;
		scanf("%d%d%d", &b, &c, &x[i]);
		if(x2i.find(x[i]) == x2i.end()){
			x2i[x[i]] = x2i.size();
		}
		x[i] = x2i[x[i]];
		idxans[x[i]].push_back(i);
		a[x[i]].push_back(b);
		t[x[i]].push_back(c);
	}
	for(int z = 0; z < 1100000; z++){
		if(a[z].size() == 0){
			continue;
		}
		for(int r = 0; r < t[z].size(); r++){
			sorted[r] = t[z][r];
		}
		sort(sorted, sorted+t[z].size());
		map<int,int> q;
		for(int r = 0; r < t[z].size(); r++){
			q[sorted[r]] = r+1;
		}
		for(int r = 0; r < t[z].size(); r++){
			t[z][r] = q[t[z][r]];
			if(a[z][r] == 1){
				set1(t[z][r],1);
			} else if(a[z][r] == 2){
				set1(t[z][r],-1);
			} else {
				ans[idxans[z][r]] = get(t[z][r]);
			}
		}
		for(int r = 0; r < t[z].size(); r++){
			if(a[z][r] == 1){
				set1(t[z][r],-1);
			} else if(a[z][r] == 2){
				set1(t[z][r],1);
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(ans[i] >= 0){
			printf("%d\n", ans[i]);
		}
	}
}