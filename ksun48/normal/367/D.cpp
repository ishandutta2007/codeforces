#include<iostream>
#include<vector>
#include<set>
using namespace std;
typedef long long LL;

int n, m, d;
int notgood[1 << 20];
void dfs(int k){
	if(notgood[k]) return;
	notgood[k] = 1;
	for(int i = 0; i < m; i++){
		if(((1<<i) & k) == (1<<i)){
			dfs(k-(1<<i));
		}
	}
}
// 2 1 2
int main(){
  cin >> n >> m >> d;
  int stuff[n];
  for(int i = 0; i < (1<<m); i++){
	  notgood[i] = 0;
  }
  for(int i = 0; i < m; i++){
	  int a;
	  cin >> a;
	  for(int j = 0; j < a; j++){
		  int r;
		  cin >> r;
		  stuff[r-1] = i;
	  }
  }
  //0 1 0 2 0 1 0 (3 7 5 7 3 -> 4 0 2 0 4, 1,2,1,4,1,2,1)
  int freq[m];
  for(int i = 0; i < m; i++) freq[i] = 0;
  for(int j = 0; j < d; j++){
	  freq[stuff[j]]++;
  }
  for(int i = 0; i+d-1 < n; i++){
	  int k = 0;
	  if(i >= 1){
		  freq[stuff[i-1]]--;
		  freq[stuff[i+d-1]]++;
	  }
	  for(int j = 0; j < m; j++){
		  if(freq[j] > 0){
			  k |= (1 << j);
		  }
	  }
	  dfs((1<<m) - 1 - k);
  }
  int ans = m;
  for(int k = 0; k < (1<<m); k++){
	  if(notgood[k]) continue;
	  int cur = 0;
	  for(int i = 0; i < m; i++){
		  if(((1<<i) & k) == (1<<i)){
			  cur++;
		  }
	  }
	  ans = min(cur, ans);
  }
  cout << ans << endl;
}