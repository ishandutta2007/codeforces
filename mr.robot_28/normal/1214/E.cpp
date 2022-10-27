#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <assert.h>
#include <queue>
#include <string.h>
#include <string>
#include <set>
#include <memory.h>
#include <stack>
#include <functional>
#include <bitset>
#include <math.h>
using namespace std;
#define ll long long
 
const int N = 2e5+15;
int nodeList[N];
pair<int,int> d[N];
void solve() {
    int n;
    scanf("%d",&n);
 
    for(int i=1;i<=n;++i) {
        scanf("%d",&d[i].first);
        d[i].second = i;
    }
    int l = 2e5,r = 2e5;
    sort(d+1,d+n+1);
    reverse(d+1,d+n+1);
    for(int i=1;i<=n;++i) {
        nodeList[i] = d[i].second*2 - 1;
    }
    vector<pair<int,int> > edge;
    for(int i=1;i<=n;++i) {
        if(i+1<=n) {
            edge.push_back(make_pair(nodeList[i],nodeList[i+1]));
        }
        int b = d[i].second*2;
        int ind = i + d[i].first;
        edge.push_back(make_pair(nodeList[ind-1],b));
        if(nodeList[ind] ==0) {
            nodeList[ind] = b;
        }
    }
    assert((int)edge.size() == 2*n-1);
    for(int i=0;i<(int)edge.size();++i) {
        printf("%d %d\n",edge[i].first,edge[i].second);
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    solve();
}