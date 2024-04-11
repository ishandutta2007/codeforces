#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <iostream>
int Max(int a, int b) {
  return (a > b ? a : b);
}
using namespace std;
int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int a;
  cin >> a;
  char names[a][101];
  char len[a];
  int k;
  int taxi[a], pizza[a], girls[a];
  int maxi = 0, mizza = 0, mirls = 0;
  for(int i = 0; i < a; i++){
    taxi[i] = 0; pizza[i] = 0; girls[i] = 0;
    cin >> k >> names[i];
    char phone[9];
    for(int j = 0; j < k; j++){
      cin >> phone;
      if(phone[0] == phone[1] && phone[0] == phone[3] && phone[0] == phone[4] && phone[0] == phone[6] && phone[0] == phone[7]){
	taxi[i]++;
      } else if (phone[0] > phone[1] && phone[1] > phone[3] && phone[3] > phone[4] && phone[4] > phone[6] && phone[6] > phone[7]) {
	pizza[i]++;
      } else {
	girls[i]++;
      }
    }
    maxi = Max(maxi, taxi[i]);
    mizza = Max(mizza, pizza[i]);
    mirls = Max(mirls, girls[i]);
  }
  int num;  
  num = 0;
  cout << "If you want to call a taxi, you should call: ";
  for(int i = 0; i < a; i++){
    if(taxi[i] == maxi){
      if(num == 0){
	num = 1;
      } else {
	cout << ", ";
      }
      cout << names[i];
    }
  }
  cout << "." << endl;
  num = 0;
  cout << "If you want to order a pizza, you should call: ";
  for(int i = 0; i < a; i++){
    if(pizza[i] == mizza){
      if(num == 0){
	num = 1;
      } else {
	cout << ", ";
      }
      cout << names[i];
    }
  }
  cout << "." << endl;  
  num = 0;
  cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
  for(int i = 0; i < a; i++){
    if(girls[i] == mirls){
      if(num == 0){
	num = 1;
      } else {
	cout << ", ";
      }
      cout << names[i];
    }
  }
  cout << "." << endl;
}