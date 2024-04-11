#include <bits/stdc++.h>
using namespace std;

int t, n, a[2], b[2], K;

int main(void) {
  scanf("%d%d%d%d%d", &t, &n, &a[0], &a[1], &K);
  b[0] = (n + 1) / 2;
  b[1] = n / 2;
  if(a[0] < a[1]) {
    swap(a[0], a[1]);
    swap(b[0], b[1]);
  }
  //cerr << b[0] << " " << b[1] << " " << K << endl;
  if(K <= b[0]) {
    printf("%lld\n", min(1LL * t, (1LL * a[0] * b[0] + 1LL * a[1] * b[1]) / K));
  } else {
    int tmp = K;
    K -= b[0];
    if(K > b[1]) {
      puts("0");
      return 0;
    }
    int B = b[1] - K, A = a[0] - a[1] - 1;
    if(A <= 0) {
      printf("%lld\n", min(1LL * t, (1LL * a[0] * b[0] + 1LL * a[1] * b[1]) / tmp));
      return 0;
    }
    if(!B) {
      printf("%d\n", min(t, a[1]));
      return 0;
    }
    long long cnt = 1LL * A / B * b[1] + (A % B ? 1 : 0) * (1LL * A % B * b[1] / B + bool(1LL * A % B * b[1] % B));
    
    long long mi = min(1LL * a[0], 1LL * a[1] * b[1] / K);
    //cerr << cnt << " " << mi << endl;
    if(cnt <= mi) {
      printf("%lld\n", min(1LL * t, (1LL * a[0] * b[0] + 1LL * a[1] * b[1]) / tmp));
      return 0;
    } 
    cout << min(1LL * t, mi) << endl;
  }
  return 0;
}