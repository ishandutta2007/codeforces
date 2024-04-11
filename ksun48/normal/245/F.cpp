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

int myGetline(char *line) {
  int nc=0;
  while(scanf("%c", &line[nc])==1) {
    nc++;
    if(line[nc-1] == '\n') {
      break;
    }
  }
  line[nc-1] = '\0';
  return nc-1;
}
char tmpstr[5100000];


int DEBUG = 0;
main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  int n, m;
  cin >> n >> m;
  vector<vector<char> > str;
  while(myGetline(tmpstr) >= 0 ) {
    if(strlen(tmpstr)==0) {
      continue;
    }
    vector<char> vecstr;
    for(int i = 0; i < 19; i++){
      vecstr.push_back(tmpstr[i]);
    }
    str.push_back(vecstr);
  }
  int z = str.size();
  for(int i = 0; i < z; i++){
    for(int j = 0; j < str[i].size(); j++){
      if(DEBUG)cout << str[i][j];
    }
    if(DEBUG)cout << endl;
  }
  int time[z];
  int month[13] = {0,31,60,91,121,152,182,213,244,274,305,335,366};
  for(int i = 0; i < z; i++){
    time[i] = 0;
    time[i] += (str[i][17]-'0')*10+(str[i][18]-'0');
    time[i] += 60*((str[i][14]-'0')*10+(str[i][15]-'0'));
    time[i] += 60*60*((str[i][11]-'0')*10+(str[i][12]-'0'));
    time[i] += 24*60*60*((str[i][8]-'0')*10+(str[i][9]-'0'));
    time[i] += month[((str[i][5]-'0')*10+(str[i][6]-'0'))-1]*24*60*60;
    //if(DEBUG) cout << time[i] << endl;
  }
  set<int> timeset;
  for(int i = 0; i < z; i++){
    timeset.insert(time[i]);
    if(DEBUG) cout << time[i] << " " << time[i] + n << endl;
    timeset.insert(time[i]+n);
  }
  int k = (int)(timeset.size());
  int a = 0;
  int distime[k];
  map<int,int> timemap;
  if(DEBUG) cout << endl;
  for(set<int>::iterator iter = timeset.begin(); iter != timeset.end(); iter++){
    distime[a] = *iter;
    timemap[distime[a]] = a;
    if(DEBUG) cout << distime[a] << endl;
    a++;
  }
  int gained[k];
  for(int i = 0; i < k; i++){
    gained[i] = 0;
  }
  if(DEBUG) cout << endl;
  for(int i = 0; i < z; i++){
    if(DEBUG) cout << time[i] << " " << timemap[time[i]]<< endl;
    gained[timemap[time[i]]]++;
    if(DEBUG) cout << time[i] +n << " " << timemap[time[i]+n]<< endl;
    gained[timemap[time[i]+n]]--;
  }
  if(DEBUG) cout << endl;
  for(int i = 0; i < k; i++){
    if(DEBUG) cout << gained[i] << endl;
  }
  if(DEBUG) cout << endl;
  int cumsum = 0;
  for(int i = 0; i < k; i++){
    cumsum += gained[i];    
    if(DEBUG) cout << cumsum << endl;
    if(cumsum >= m){
      int endtime = distime[i];
      int sec = endtime % 60;
      endtime = (endtime-sec)/60;
      int min = endtime % 60;
      endtime = (endtime-min)/60;
      int hr = endtime % 24;
      endtime = (endtime-hr)/24;
      int mon;
      int day;
      for(int a = 0; a < 13; a++){
	if(DEBUG) cout << endtime << " " << month[a] << endl;
	if(endtime < month[a]){
	  mon = a;
	  day = endtime-month[a-1];
	  break;
	}
      }
      char hm[19];
      hm[0] = '2';
      hm[1] = '0';
      hm[2] = '1';
      hm[3] = '2';
      hm[4] = '-';
      hm[5] = '0' + (mon - mon%10)/10;
      hm[6] = '0' + mon % 10;
      hm[7] = '-';
      hm[8] = '0' + (day - day %10)/10;
      hm[9] = '0' + day % 10;
      hm[10] = ' ';
      hm[11] = '0' + (hr - hr %10)/10;
      hm[12] = '0' + hr % 10;
      hm[13] = ':';
      hm[14] = '0' + (min - min %10)/10;
      hm[15] = '0' + min % 10;
      hm[16] = ':';
      hm[17] = '0' + (sec - sec %10)/10;
      hm[18] = '0' + sec % 10;
      for(int i = 0; i < 19; i++){
	cout << hm[i];
      }
      cout << endl;
      exit(0);
    }
  }
  cout << -1 << endl;
}

// g++ 245F.cpp; cat 245F.in | ./a.out