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
  int x1, x2, a, b;
  cin >> x1 >> x2 >> a >> b;
  if(a > 0){
    if(x1 > x2){
      cout << "DRAW" << endl;
      exit(0);
    } else {
      int mod = ((x2-x1) % (a+b));
      if(mod == 0){
	cout << "SECOND" << endl;
	exit(0);	
      } else if (mod <= b && mod >= a){
	cout << "FIRST " << endl;
	cout << mod + x1 << endl;
	exit(0);
      } else {
	cout << "DRAW" << endl;
	exit(0);
      }
    }
  } else if(a == 0){
    if((x2-x1) > 0 && (x2-x1) <= b){
      cout << "FIRST " << endl;
      cout << x2 << endl;
      exit(0);
    } else {
      cout << "DRAW" << endl;
      exit(0);
    }
  } else if(b == 0){
    if((x2-x1) < 0 && (x2-x1) >= a){
      cout << "FIRST " << endl;
      cout << x2 << endl;
      exit(0);
    } else {
      cout << "DRAW" << endl;
      exit(0);
    }
  } else if(b < 0){
    if(x1 < x2){
      cout << "DRAW" << endl;
      exit(0);
    } else {
      int mod = ((x1-x2) % (-a-b));
      if(mod == 0){
	cout << "SECOND" << endl;
	exit(0);	
      } else if (mod <= -a && mod >= -b){
	cout << "FIRST " << endl;
	cout << x1-mod << endl;
	exit(0);
      } else {
	cout << "DRAW" << endl;
	exit(0);
      }
    }
  } else {
    if((x2-x1) <= b && (x2-x1) >= a){
      cout << "FIRST " << endl;
      cout << x2 << endl;
    } else {
      cout << "DRAW" << endl;
      exit(0);
    }
  }
  
}