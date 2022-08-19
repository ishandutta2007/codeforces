#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <iostream>
#include <string.h>
using namespace std;
int DEBUG = 0;
int exp(int a){
  if(a == 0){
    return 1;
  }
  return 26*exp(a-1);
}
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int a;
  scanf("%d", &a);
  for(int k = 0; k < a; k++){
    char str[100];
    cin >> str;
    int num[2];
    num[0] = 1; num[1] = 0;
    int len = strlen(str);
    int curr = 0;
    int start[4];
    start[0] = 0;
    start[1] = 0;
    start[2] = 0;
    start[3] = 0;
    int pwn = 0;
    for(int j = 0; j < len; j++){
      int k;
      k = 1;
      if(str[j] <= 'Z' && 'A' <= str[j]){
	k = 0;
      }
      if(k != curr){
	num[k]++;
	pwn++;
	start[pwn] = j;
      }
      curr = k;
    }
    if(num[0] == 1){
      cout << "R";
      for(int i = start[1]; i < len; i++){
	cout << str[i];
      }
      cout << "C";
      int a = 0;
      for(int i = 1; i < start[1]; i++){
	a += exp(i);
      }
      int b = 0;
      for(int i = 0; i < start[1]-1; i++){
	b += (str[i]-'A');
	b *= 26;
      }
      b += str[start[1]-1]-'A'+1;
      cout << a+b << endl;
    } else {
      int b = str[start[3]]-'0';
      for(int ll = start[3]+1; ll < len; ll++){
	b *= 10;
	b += str[ll]-'0';
      }
      b--;
      int i;
      for(i = 1; i < 66; i++){
	if(b >= exp(i)){
	  b -= exp(i);
	} else {
	  break;
	}
      }
      char pwn[i];
      for(int k = i-1; k > 0; k--){
	pwn[k] = b % 26 + 'A';
	b = (b - b % 26)/26;
      }
      pwn[0] = b % 26 + 'A';
      b = (b - b % 26)/26;
      for(int k = 0; k < i; k++){
	printf("%c", pwn[k]);
      }
      for(int k = start[1]; k < start[2]; k++){
	cout << str[k];
      }
      cout << endl;
    }
  }
}