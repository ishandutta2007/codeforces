  #include <iostream>
  #include<iostream>
  #include<cstdio>
  #include<cstdlib>
  #include<algorithm>
  #include<vector>
  #include<string>
  #include<set>
  #include<map>
  #include<cmath>
  #include<math.h>
  #include<memory.h>
  #include<assert.h>
  #include<string>
  using namespace std;
  #include<fstream>
  ifstream fin("race.in");
  ofstream fout("race.out");


  int main(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int arr[1000001]={};
    int first[26]={};
    int last[26]={};
    set<int> found;
    //ascii A is 65
    //have an array of the size of string, count over laps between letters. if the max number of overlaps is larger than k, then YES
    for (int i = 0; i < 26; i++){
      first[i] = -1;
      last[i] = -1;
    }
    for (int i = 0; i < n; i++){
      int index = s[i] - 'A';
      
      if (found.find((index)) == found.end()){
        first[index] = i;
      }
      found.insert(index);
      last[index] = i;
    }
    for (int num : found){
      for (int i = first[num]; i <= last[num]; i++){
        arr[i]++;
      }
    }
    int max = 0;
    for (int i = 0; i < n; i++){
      if (arr[i] > max) max = arr[i];
    }
    if (max > k){
      return cout << "YES", 0;
    }
    return cout << "NO", 0;
  }