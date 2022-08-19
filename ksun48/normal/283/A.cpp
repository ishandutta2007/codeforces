#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <set>
#include <queue>
#include <algorithm>
#include <complex>
#include <deque>
#include <map>
#include <utility>
#include <limits>
#include <vector>
// numeric_limits<int>::max()
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
int DEBUG = 0;
main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);
  
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  LL n;
  cin >> n;
  vector<LL> diff;
  diff.push_back(0);
  LL sum = 0;
  LL last = 0;
  for(LL i = 0; i < n; i++){
    LL t;
    cin >> t;
    if(t == 1){
      LL a, x;
      cin >> a >> x;
      sum += a*x;
      diff[0] += x;
      if(diff.size() == a){
	last += x;
      } else {
	diff[a] -= x;
      }
    } else if(t == 2){
      LL k;
      cin >> k;
      diff.push_back(k-last);
      last = k;
      sum += k;
    } else if(t == 3){
      sum -= last;
      last -= diff[diff.size()-1];
      diff.pop_back();
    }
    double ans = 1.0*sum/(1.0*diff.size());
    //cout << last << " ";
    /*int sum = 0;
    for(int i = 0; i < diff.size(); i++){
    sum += diff[i];
    cout << sum;
    if(i < diff.size()-1) cout << " ";
    }
    cout << "=" << last << " ";*/
    
    printf("%.12lf\n", ans);
  }
  
}