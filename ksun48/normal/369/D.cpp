#include<iostream>
#include<utility>
#include<queue>
using namespace std;
typedef long long LL;
int n, k;
int p[3001];
int total[3001];
int empty; // nobody
int possible[3001]; // single
int mindepth[3001][3001];
int vis[3001][3001];
queue<pair<int,int> > search;

int main(){
  cin >> n >> k;
  if(n == 1){
	  cout << 1 << endl;
	  return 0;
  }
  empty = -1;
  for(int i = 0; i < n; i++){
	  possible[i] = -1;
	  for(int j = 0; j < n; j++){
		  mindepth[i][j] = -1;
		  vis[i][j] = 0;
	  }
  }
  for(int i = 0; i < n; i++) cin >> p[i];
  for(int i = 0; i < n; i++) if(p[i] > 0 && p[i] < 100) p[i] = 1;
  for(int i = 0; i < n; i++) if(p[i] == 100) p[i] = 2;
  total[n-1] = p[n-1];
  for(int i = n-2; i >= 0; i--){
	  total[i] = max(total[i+1], p[i]);
  }
  mindepth[0][1] = 0;
  search.push(make_pair(0, 1));
  while(!search.empty()){
	  pair<int,int> a = search.front();
	  search.pop();
	  int i = a.first;
	  int j = a.second;
	  if(vis[i][j] == 1) continue;
	  vis[i][j] = 1;
	  if(mindepth[i][j] >= k){
		  continue;
	  }
	  int depth = mindepth[i][j];
	  int yesi = total[j];
	  int yesj = p[i];
	  if(yesi >= 1 && yesj >= 1){
		  if(j == n-1){
			  if(empty == -1) empty = depth+1;
		  } else if(j == n-2){
			  if(possible[n-1] == -1) possible[n-1] = depth+1;
		  } else {
			  if(mindepth[j+1][j+2] == -1){
			  mindepth[j+1][j+2] = depth+1;
			  search.push(make_pair(j+1, j+2));
		      }
		  }
	  }
	  if(yesi <= 1 && yesj >= 1){
		  if(j == n-1){
			  if(possible[i] == -1) possible[i] = depth+1;
		  } else {
			  if(mindepth[i][j+1] == -1){
			  mindepth[i][j+1] = depth+1;
			  search.push(make_pair(i, j+1));
		      }
		  }
	  }
	  if(yesi >= 1 && yesj <= 1){
		  if(j == n-1){
			  if(possible[n-1] == -1) possible[n-1] = depth+1;
		  } else {
			  if(mindepth[j][j+1] == -1){
				  mindepth[j][j+1] = depth+1;
				  search.push(make_pair(j, j+1));
			  }
		  }
	  }
  }
  int ans = 0;
  if(empty >= 0){
	  ans++;
	  //cout << "empty" << endl;
  }
  for(int i = 0; i < n; i++){
	  if(possible[i] >= 0){
		  ans++;
		  //cout << i << endl;
	  }
	  for(int j = 0; j < n; j++){
		  if(mindepth[i][j] >= 0){
			  ans++;
			  //cout << i << " " << j << endl;
		  }
	  }
  }
  cout << ans << endl;
}