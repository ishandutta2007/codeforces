#include <iostream>

using namespace std;

int n;
int a[105];

int main(void)
{
  cin >> n;
  for(int i =1;i <=n; i++) cin >>a[i];

  for(int k = 1; k <= 1000; k++){
    int sum1 = 0, sum2 = 0;
    for(int i = 1;i <= n; i++){
      if(a[i] > k) goto end;
      sum1 += k - a[i];
      sum2 += a[i];
    }
    if(sum1 > sum2){
      cout << k << endl;
      return 0;
    }
    end:;
  }
  return 0;
}