#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
#include <set>
#include <queue>
#include <complex>
#include <deque>
#include <map>
using namespace std;
#define LL int64_t 

int nd(LL k){ // number of digits
  int a = 0;
  LL c = k;
  while(c > 0){
    a++;
    c = (c - c % 10)/10;
  }
  return a;
}
LL lead(LL k){ // leading digit
  LL c = k;
  while(c > 9){
    c = (c - c % 10)/10;
  }
  return c;
}

LL p(LL j, int a){ // j^a power
  if(a == 0){
    return 1;
  }
  return j*p(j, a-1);
}

int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;

  LL ans = 0;

  LL a, b;
  cin >> a >> b;
  for(int i = 1; i <= 18; i++){
    for(int j = 1; j <= 9; j++){
      LL small;
      LL large;
      if(i == 1){
	small = j;
	large = j;
	//cout << small << " " << large << endl;
      } else {
	small = j*(p(10, i-1)+1);
	large = (j+1)*(p(10, i-1))-10+j;
	//cout << small << " " << large << endl;
      }
      if(a >= small && b <= large){
	LL ra = j + 10*((LL)((a+9-j)/10));
	LL rb = j + 10*((LL)((b-j)/10));
	ans += (rb-ra)/10+1;
	//cout << small << " " << large << " " << ra << " " << rb << " " << (rb-ra)/10 + 1 << endl;
      } else if(a >= small && a <= large){
	LL ra = j + 10*((LL)((a+9-j)/10));
	ans += (large-ra)/10+1;
	//cout << small << " " << large << " " << ra << " " << large << " " << (large-ra)/10 + 1 << endl;
      } else if(b <= large && b >= small){
	LL rb = j + 10*((LL)((b-j)/10));
	ans += (rb-small)/10+1;
	//cout << small << " " << large << " " << small << " " << rb << " " << (rb-small)/10 + 1 << endl;
      } else if(a <= small && b >= large){
	ans += (large-small)/10+1;
	//cout << small << " " << large << " " << small << " " << large << " " << (large-small)/10 + 1 << endl;
      }
    }
  }
  cout << ans << endl;
  //int check = 0;
  //for(int i = a; i <= b; i++){
  //  if(lead(i) == i % 10){
  //    check++;
  //  }
  //}
  //cout << check << endl;
}