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
LL stuff[33] = {8533824895,4369023041,6246905437,6253595997,6261859165,4379596097,
8545195391,31973120,5359932369,1753546555,2732754382,6470747678,882671615,1254829703,
2192389205,12462605,3051539536,3802390309,595890157,2193723792,910809452,3401336238,
3769820759,1067701411,527048132,3511002880,3043217791,7268642369,1058285917,3085511773,
493838941,255747649,4625435519};
main(int argc, char **argv) {
  //int a;
  //scanf("%d", &a);

  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int a1, a2;
  cin >> a1 >> a2;
  LL num = stuff[a1];
  for(int i = 0; i < a2; i++) num /= 2;
  cout << num % 2 << endl;
}