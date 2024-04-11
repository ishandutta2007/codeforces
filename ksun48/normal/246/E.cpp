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
#include <algorithm>
#include <map>

using namespace std;
#if 0
struct Timer {
  void start() {
    ts.tv_sec = 0; ts.tv_nsec = 0;
    clock_settime(CLOCK_PROCESS_CPUTIME_ID, &ts);
  }
  double get_ms() {
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);
    return ts.tv_sec * 1000.0 + ts.tv_nsec/1000.0/1000.0;
  }
  double get_us() {
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);
    return ts.tv_sec * 1000.0 * 1000.0 + ts.tv_nsec/1000.0;
  }
  double get_ns() {
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);
    return ts.tv_sec * 1000.0 * 1000.0 * 1000.0 + ts.tv_nsec;
  }
  timespec ts;
};
#endif

#define LL int64_t // 64-bit long long int, use %I64d for scan and printf
int DEBUG = 0;
int n;
int nNodes = 0;
int nodemap[110000];
int nodenum[110000];
int ndepth[110000];
int lnode[110000];
int rnode[110000];
vector<int> nodedepth[110000];
vector<int> children[110000];
int parent[110000];
map <pair<int, int>, int> depth_low_upper_map[110000];
int freq[110000];
int nameid[110000];
void search(int node, int depth){
  nodemap[node] = nNodes;
  nodenum[nNodes] = node;
  nodedepth[depth].push_back(nodemap[node]);
  ndepth[nodemap[node]] = depth; 
  //if(DEBUG) cout << node << " " << nodemap[node] << " depth " << depth <<  endl;
  nNodes++; 
  lnode[nodemap[node]] = nNodes;
  for(int i = 0; i < children[node].size(); i++){
    search(children[node][i], depth+1);
  }
  rnode[nodemap[node]] = nNodes-1;
}
int main(int argc, char **argv) {
  DEBUG = (argc>=2) ? atoi(argv[1]) : 0;
  //Timer mytimer;
  //mytimer.start();
  int n;
  cin >> n;
  int numname = 0;
  map<string, int> namemap;
  parent[0] = -1;
  for(int i = 1; i <= n; i++){
    char name[22];
    int a;
    //cin >> name >> a;
    scanf("%s%d", name, &a);
    if(namemap.count(name) == 1){
      nameid[i] = namemap[name];
    } else {
      namemap[name] = numname++;
      nameid[i] = namemap[name];
    }
    parent[i] = a;
    children[a].push_back(i);
  }
  search(0, 0);
  //if(DEBUG) cout << "after search mytimer.get_ms()= " << mytimer.get_ms() << " ms" << endl;
  if(DEBUG) {
    cout << endl;
    for(int i = 0; i <= n; i++){
      cout << i << " " << lnode[i] << " " << rnode[i] << endl;
    }
  }
  int m;
  cin >> m;
  for(int i = 0; i < m; i++){
    int node, d;
    //cin >> node >> d;
    scanf("%d%d", &node, &d);
    // if(DEBUG) cout << ndepth[nodemap[node]] << " " << d << endl;
    int k = nodemap[node];
    if(ndepth[k] + d > 101000){
      cout << 0 << endl;
    } else {
      if(0) {
        set<int> distnames;
        vector<int>::iterator lb = lower_bound(nodedepth[ndepth[k]+d].begin(), nodedepth[ndepth[k]+d].end(), lnode[k]);
        vector<int>::iterator ub = upper_bound(nodedepth[ndepth[k]+d].begin(), nodedepth[ndepth[k]+d].end(), rnode[k]);
        for(vector<int>::iterator it = lb; it != ub; it++) {
          distnames.insert(nameid[nodenum[*it]]);
        }
        cout << distnames.size() << endl;
        if(DEBUG) {
          cout << "distnames ";
          for(set<int>::iterator it=distnames.begin(); it!=distnames.end(); it++) {
            cout << " " << *it;
          }
          cout << endl;
        }
      } else {
        int depth = ndepth[k] + d;
        vector<int>::iterator lb = lower_bound(nodedepth[depth].begin(), nodedepth[depth].end(), lnode[k]);
        vector<int>::iterator ub = upper_bound(nodedepth[depth].begin(), nodedepth[depth].end(), rnode[k]);
        int lbi = lb - nodedepth[depth].begin();
        int ubi = ub - nodedepth[depth].begin();
        if(depth_low_upper_map[depth].find(make_pair(lbi, ubi)) == depth_low_upper_map[depth].end()) {
          int sum = 0;
          for(int i=lbi; i<ubi; i++) {
            if(freq[nameid[nodenum[ nodedepth[depth][i] ]]]==0) {
               sum++;
               freq[nameid[nodenum[ nodedepth[depth][i] ]]]=1;
            }
          }
          depth_low_upper_map[depth][make_pair(lbi, ubi)] = sum;
          for(int i=lbi; i<ubi; i++) freq[nameid[nodenum[ nodedepth[depth][i] ]]]=0;
        }
        cout << depth_low_upper_map[depth][make_pair(lbi, ubi)] << endl;
      }
    }
  }
  //if(DEBUG) cout << "after query mytimer.get_ms()= " << mytimer.get_ms() << " ms" << endl;
  
}