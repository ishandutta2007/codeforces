#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;

int main(){
  LL n, m, p;
  cin >> n >> m >> p;
  LL a[n];
  LL b[m];
  for(LL i = 0; i < n; i++) cin >> a[i];
  for(LL i = 0; i < m; i++) cin >> b[i];
  set<LL> k;
  for(LL i = 0; i < m; i++) k.insert(b[i]);
  map<LL,LL> maps;
  LL i = 0;
  while(!k.empty()){
	  maps[*k.begin()] = i;
	  i++;
	  k.erase(k.begin());
  }
  for(LL i = 0; i < n; i++){
	  if(maps.find(a[i]) != maps.end()){
		  a[i] = maps[a[i]];
	  } else {
		  a[i] = m;
	  }
  }
  for(LL i = 0; i < m; i++) b[i] = maps[b[i]];
  LL answers[200010];
  LL sz = 0;
  for(LL i = 0; i < p; i++){
	  if(i+(m-1)*p >= n){
		  break;
	  }
	  LL stuff[m+1];
	  for(LL j = 0; j <= m; j++) stuff[j] = 0;
	  for(LL j = 0; j < m; j++) stuff[b[j]]--;
	  for(LL j = 0; j < m; j++){
		  stuff[a[i+j*p]]++;
	  }
	  /*for(LL j = 0; j <= m; j++){
		  cout << j << " " << stuff[j] << endl;
	  }
	  cout << endl;*/
	  LL numdiff = 0;
	  for(LL j = 0; j <= m; j++){
		  if(stuff[j] != 0) numdiff++;
	  }
	  if(numdiff == 0) answers[sz++] = i;
	  LL cur = i;
	  while(cur+p+(m-1)*p < n){
		  cur += p;
		  if(stuff[a[cur-p]] == 0) numdiff++;
		  stuff[a[cur-p]]--;
		  if(stuff[a[cur-p]] == 0) numdiff--;
		  if(stuff[a[cur+(m-1)*p]] == 0) numdiff++;
		  stuff[a[cur+(m-1)*p]]++;
		  if(stuff[a[cur+(m-1)*p]] == 0) numdiff--;
		  if(numdiff == 0) answers[sz++] = cur;
		 /* for(LL j = 0; j <= m; j++){
			  cout << j << " " << stuff[j] << endl;
		  }
		  cout << numdiff << endl;
		  cout << endl;*/
		  //cout << cur << " " << numdiff << " " << endl;
	  }
  }
  cout << sz << endl;
  sort(answers, answers+sz);
  for(LL i = 0; i < sz; i++){
	  cout << answers[i]+1 << " ";
  }
  cout << endl;
}