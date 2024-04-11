#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#include <iostream>
using namespace std;

#define LOGSZ 20

int tree[(1<<LOGSZ)+1];
int N = (1<<LOGSZ);

// add v to value at x
void add(int x, int v) {
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
	for(int i = 0; i <= N; i++){
		tree[i] = 0;
	}
	int n;
	cin >> n;
	map<int,int> c;
	int l[n];
	int r[n];
	int ans[n];
	map<pair<int,int>,int> idx;
	int stuff[2*n];
	for(int i = 0; i < n; i++){
		cin >> l[i] >> r[i];
		stuff[i] = l[i];
		stuff[i+n] = r[i];
	}
	sort(stuff, stuff+2*n);
	for(int i = 0; i < 2*n; i++){
		c[stuff[i]] = i+1;
	}
	pair<int,int> v[n];
	for(int i = 0; i < n; i++){
		v[i].first = c[l[i]];
		v[i].second = c[r[i]];
		idx[make_pair(v[i].first,v[i].second)] = i;
	}
	sort(v, v+n);
	for(int i = n-1; i >= 0; i--){
		ans[idx[make_pair(v[i].first,v[i].second)]] = get(v[i].second);
		add(v[i].second,1);
	}
	for(int i = 0; i < n; i++){
		cout << ans[i] << endl;
	}


}