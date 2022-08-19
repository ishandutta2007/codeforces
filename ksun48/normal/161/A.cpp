#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf

int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  int sold[n], vests[m];
  for(int i = 0; i < n; i++) cin >> sold[i];
  for(int i = 0; i < m; i++) cin >> vests[i];
  int vestnum = 0;
  int soldier = 0;
  int equip = 0;
  int sequip[m+n];
  int vequip[m+n];
  while(vestnum < m && soldier < n){
    if(vests[vestnum]-sold[soldier] > y){
      soldier++;
    } else if (sold[soldier]-vests[vestnum] > x){
      vestnum++;
    } else {
      sequip[equip] = soldier + 1;
      vequip[equip] = vestnum + 1;
      soldier ++, vestnum ++, equip ++;
    }
  }
  cout << equip << endl;
  for(int i = 0; i < equip; i++){
    cout << sequip[i] << " " << vequip[i] << endl;
  }
  exit(0);
}