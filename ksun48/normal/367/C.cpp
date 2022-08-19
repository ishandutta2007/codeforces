#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;

int main(){
  int n, m;
  cin >> n >> m;
  int q[m];
  LL w[m];
  for(int i = 0; i < m; i++) cin >> q[i] >> w[i];
  for(int i = 0; i < m; i++) w[i] = -w[i];
  sort(w, w+m);
  for(int i = 0; i < m; i++) w[i] = -w[i];
  int ans=1;
  for(int i = 2; i <= 3000; i++){
	  if(i % 2 == 0){
		  if(i*i/2 <= n){
			  ans = i;
		  } else {
			  break;
		  }
	  } else {
		  if(i*(i-1)/2 +1<= n){
			  ans = i;
		  } else {
			  break;
		  }
	  }
  }
  LL sum = 0;
  for(int i = 0; i < min(m,ans); i++){
	  sum += w[i];
  }
  cout << sum << endl;
}