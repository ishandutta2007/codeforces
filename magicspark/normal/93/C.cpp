#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

int a[100];
string command[100];

string ex(int id){
    string ans = "eax";
    ans[1] += id;
    return ans;
}

bool dfs(int MAX, int pos, int N){
    int i,j,k;
    
    if(a[pos] > N) return false;
    if(pos == MAX){
        if(a[pos] != N) return false;
        cout << MAX << endl;
        REP(i,MAX) cout << command[i] << endl;
        return true;
    }
    
    REP(i,pos+1) for(k=1;k<=8;k*=2){
        a[pos+1] = a[i] * k;
        if(a[pos+1] > N) continue;
        if(pos+1 == MAX && a[pos+1] != N) continue;
        command[pos] = "lea " + ex(pos+1) + ", [" + (char)('0' + k) + "*" + ex(i) + "]";
        if(dfs(MAX,pos+1,N)) return true;
    }
    
    REP(i,pos+1) REP(j,pos+1) for(k=1;k<=8;k*=2){
        a[pos+1] = a[i] * k + a[j];
        if(a[pos+1] > N) continue;
        if(pos+1 == MAX && a[pos+1] != N) continue;
        command[pos] = "lea " + ex(pos+1) + ", [" + ex(j) + " + " + (char)('0' + k) + "*" + ex(i) + "]";
        if(dfs(MAX,pos+1,N)) return true;
    }
    return false;
}

int main(void){
    int N,i;
    cin >> N;
    a[0] = 1;
    for(i=0;;i++) if(dfs(i,0,N)) break;
    return 0;
}