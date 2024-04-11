#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <iostream>

using namespace std;

struct OBJECT{
  int cost;
  int id;
};

int Min(int a, int b) {
  return (a < b ? a : b);
}

int DEBUG = 0;

int compare_NODE_dec (const void * a, const void * b) {
  if( (*(OBJECT*)b).cost > (*(OBJECT*)a).cost ) return 1;
  else if( (*(OBJECT*)b).cost < (*(OBJECT*)a).cost ) return -1;
  else return 0;
}

int main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, k;
  cin >> n >> k;
  OBJECT stools[n];
  int ns = 0;
  OBJECT pencils[n];
  int np = 0;
  int a; int b;
  double tcost = 0.0;
  for(int i = 1; i <= n; i++){
    cin >> a >> b;
    if(b == 1){
      stools[ns].cost = a;
      stools[ns++].id = i;
    } else {
      pencils[np].cost = a;
      pencils[np++].id = i;
    }
    tcost += a;
  }

  //if(n==1 && k==1 && ns==1 && np==0 && stools[0].cost == 1) {
  //  // DEBUGGING
  //  if(DEBUG) {
  //    cout << "HARD-CODED DEBUGGING" << endl;
  //  }
  //  cout << "0.5" << endl << "1 1" << endl;
  //  return 0;
  //}

  int cart[k][n];
  int items[k];
  for(int i = 0; i < k; i++){
    items[i] = 0;
  }
  qsort(stools,  ns, sizeof(OBJECT), compare_NODE_dec);
  qsort(pencils, np, sizeof(OBJECT), compare_NODE_dec);
  if(DEBUG) {
    cout << "tcost= " << tcost << endl;
  }
  if(ns <= k-1){
    for(int i = 0; i < ns; i++){
      cart[i][items[i]++] = stools[i].id;
      //tcost += (stools[i].cost)/2.0;
      tcost -= 1.0*(stools[i].cost)/2.0;
    }
    for(int i = 0; i < np; i++){
      int idx = Min(i+ns, k-1);
      cart[idx][items[idx]++] = pencils[i].id;
      //tcost += (pencils[i].cost)*1.0;
    }
    if(DEBUG) {
      cout << "AAA tcost= " << tcost << endl;
    }
  } else {
    for(int i = 0; i < k-1; i++){
      cart[i][items[i]++] = stools[i].id;
      //tcost += (stools[i].cost)/2.0;
      tcost -= 1.0*(stools[i].cost)/2.0;
    }
    for(int i = k-1; i < ns; i++){
      cart[k-1][items[k-1]++] = stools[i].id;
      //tcost += (stools[i].cost)*1.0;
    }
    for(int i = 0; i < np; i++){
      cart[k-1][items[k-1]++] = pencils[i].id;
      //tcost += (pencils[i].cost)*1.0;
    }
    int minCost = 0x3FFFFF;
    if(np>=1) minCost = Min(minCost, pencils[np-1].cost);
    if(ns>=1) minCost = Min(minCost, stools[ns-1].cost);
    //if(pencils[np-1].cost >= stools[ns-1].cost){
    //  tcost -= 1.0*(stools[ns-1].cost)/2.0;
    //} else {
    //  tcost -= 1.0*(pencils[np-1].cost)/2.0;
    //}
    tcost -= minCost/2.0;
  }
  if(DEBUG) {
    cout << "tcost= " << tcost << endl;
  }
  cout.precision(1);
  cout << fixed << tcost << endl;
  //printf("%.1f\n", tcost);
  //cout << tcost << endl;
  for(int i = 0; i < k; i++){
    cout << items[i];
    for(int j = 0; j < items[i]; j++){
      cout << " " << cart[i][j];
    }
    cout << endl;
  }
  exit(0);
}