#include<iostream>
using namespace std;
typedef long long LL;

LL no [33] = 
{1,2,3,5,6,9,10,13,17,31,34,37,38,41,43,45,46,49,50,53,57,71,83,111,123,391,403,437,457,471,483,511,523};
LL first[10] = {0,11,12,23,4,15,16,7,8,19};
LL dp[50];
LL last[10000];
LL realdp[10000];

int main(){
  for(LL i = 1; i < 50; i++){
    dp[i] = 0;
  }
  dp[0] = 1;
  for(LL i = 0; i < 6; i++){
    for(LL j = 49; j >= 0; j--){
      if(dp[j]){
	if(!dp[j+7]){
	  dp[j+7] = 1;
	}
	if(!dp[j+4]){
	  dp[j+4] = 1;
	}
      }
    }
  }

  last[0] = 0;
  realdp[0] = 1;
  for(LL i = 1; i < 10000; i++){
    realdp[i] = 0;
    for(LL j = i%10; j < 50 && j <= i; j+= 10){
      if(dp[j] && realdp[(i-j)/10]){
	realdp[i] = 1;
	last[i] = j;
	break;
      }
    }
  }
  LL t = 0;
  cin >> t;
  for(LL rr = 0; rr < t; rr++){
    LL a;
    cin >> a;
    int nope = 0;
    for(int k = 0; k < 33; k++){
      if(a == no[k]){
	cout << -1 << endl;
	nope = 1;
	break;
      }
    }
    if(nope) continue;
    LL k = a;
    LL array[30];
    int cur = 0;
    while(k > 0){
      if(k < 10000){
	array[cur] = last[k];
      } else {
	array[cur] = first[k%10];
      }
      k = (k-array[cur])/10;
      cur++;
    }
    LL answers[6];
    for(LL i = 0; i < 6; i++){
      answers[i] = 0;
    }
    for(LL i = cur-1; i >= 0; i--){
      for(LL j = 0; j < 6; j++){
	answers[j] *= 10;
	if(array[i] == 0){
	  
	} else if(array[i] % 7 == 0){
	  array[i] -= 7;
	  answers[j] += 7;
	} else {
	  array[i] -= 4;
	  answers[j] += 4; 
	}
      }
    }
    for(LL i = 0; i < 6; i++){
      cout << answers[i] << " ";
    }
    cout << endl;
  }
  
}