#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <stdint.h>
using namespace std;
int DEBUG = 0;
#define EPSILON .000001
int ceil(double k){
  if((k - int(k)) < EPSILON){
    return int(k);
  }
  return (int(k) + 1);
}
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n;
  cin >> n;
  int a, b, c;
  int perim[n];
  int roomh[n];
  for(int i = 0; i < n; i++){
    cin >> a >> b >> roomh[i];
    perim[i] = 2*(a+b);
  }
  int m;
  cin >> m;
  int rl[m], rw[m], rc[m];
  for(int i = 0; i < m; i++){
    cin >> rl[i] >> rw[i] >> rc[i];
  }
  int cost = 0;
  for(int i = 0; i < n; i++){
    int mcost = 4882427;
    // cout << "perim " << perim[i] << endl;
    for(int j = 0; j < m; j++){
      if(roomh[i] <= rl[j]){
	//cout << "j = " << j  << " " << rc[j] << endl;
	double kk = (double)((int(rl[j]/roomh[i]))*rw[j]);
	//cout << kk << endl;
	double k = (double)(perim[i]/kk);
	int numrolls = ceil(k);
	mcost = min(mcost, numrolls * rc[j]);
	//cout << numrolls << endl;
      }
    }
    cost += mcost;
    //cout << i << " " << mcost << endl;
  }
  cout << cost << endl;
}