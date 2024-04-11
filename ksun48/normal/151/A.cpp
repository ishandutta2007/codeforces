#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <iostream>
using namespace std;
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int t1 = int((k*l)/(n*nl));
  int t2 = int(c*d/n);
  int t3 = int(p/(n*np));
  int t = min(t1, min(t2, t3));
  cout << t << endl;
}