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
#define LL int64_t // 64-bit long long int, use %I64d for scan and printf

int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n;
  cin >> n;
  int fronts[n];
  int backs[n];
  multiset<int> front;
  multiset<int> back;
  multiset<int> allcards;
  set<int> cards;
  for(int i = 0; i < n; i++){
    cin >> fronts[i] >> backs[i];
    int a = fronts[i];
    int b = backs[i];
    front.insert(a);
    back.insert(b);
    allcards.insert(a);
    allcards.insert(b);
    cards.insert(a);
    cards.insert(b);
  }
  int hnums[10];
  int num = 0;
  for(set<int>::iterator i = cards.begin(); i != cards.end(); i++){
    if((int)allcards.count(*i) >= int((n+1)/2)){
      hnums[num++] = *i;
    }
  }
  int min = 1000000;
  for(int i = 0; i < num; i++){
    int fc = 0;
    int bc = 0;
    for(int j = 0; j < n; j++){
      if(fronts[j] == hnums[i]){
	fc++;
      } else if(backs[j] == hnums[i]){
	bc++;
      }
    }
    if(fc >= int((n+1)/2)){
      min = 0;
    } else if(fc + bc >= int(n+1)/2){
      if(int((n+1)/2)-fc < min){
	min = int((n+1)/2)-fc;
      }
    }
  }
  if(min == 1000000){
    cout << "-1" << endl;
  } else {
    cout << min << endl;
  }
  exit(0);
}