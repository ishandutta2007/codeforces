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
// numeric_limits<int>::max()
using namespace std;
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
int Min(int a, int b) {
  return (a < b ? a : b);
}
int Max(int a, int b) {
  return (a > b ? a : b);
}
int Abs(int a) {
  return (a >= 0 ? a : -a);
}
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  char s[100100];
  cin >> s;
  int freq[100000];
  for(int i = 0; i < 100000; i++){
    freq[i] = 0;
  }
  int len = strlen(s);
  int mon[13];
  mon[1] = mon[3] = mon[5] = mon[7] = mon[8] = mon[10] = mon[12] = 31;
  mon[4] = mon[6] = mon[9] = mon[11] = 30;
  mon[2] = 28;
  for(int i = 0; i < len-9; i++){
    int k = 0;
    if(s[i+2] == '-' && s[i+5] == '-'){
    if( s[i] >= '0' && s[i] <= '9'){
      k  = 10*k+(s[i]-'0');
      if( s[i+1] >= '0' && s[i+1] <= '9'){
	k  = 10*k+(s[i+1]-'0');
	if( s[i+3] >= '0' && s[i+3] <= '9'){
	  k  = 10*k+(s[i+3]-'0');
	  if( s[i+4] >= '0' && s[i+4] <= '9'){
	    k  = 10*k+(s[i+4]-'0');
	    if( s[i+6] == '2'){
	      if( s[i+7] == '0'){
		if( s[i+8] == '1'){
		  if( s[i+9] >= '0' && s[i+9] <= '9'){
		    k  = 10*k+(s[i+9]- '0');
		    int mon1 = (s[i+3]-'0')*10+(s[i+4]-'0');
		    if(mon1 > 0 && mon1 <= 12){
		      int day = (s[i]-'0')*10+(s[i+1]-'0');
		      if(day > 0 && day <= mon[mon1] ){
			if(s[i+9] >= '3' && s[i+9] <= '5'){
			  freq[k]++;
			}
		      }
		    }
		  }
		}
	      }
	    }
	  }
	}
      }
    }
  }
  }
  int max1 = 0;
  int maxk = -1;
  for(int i = 0; i < 100000; i++){
    if(freq[i] > max1){
      max1 = freq[i];
      maxk = i;
    }   
  }
  int a = maxk;
  cout << (a % 100000 - a % 10000)/10000 << (a % 10000 - a % 1000)/1000 << "-" << (a % 1000 - a % 100)/100 << (a % 100 - a % 10)/10 << "-201" << a % 10 << endl;
}