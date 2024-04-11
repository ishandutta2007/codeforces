#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

int main() {
    int st;
    scanf("%d",&st);    
    Rep(t,st){
        int n;
        scanf("%d",&n); 
        if(n==1 || n==2) printf("%d\n",0);
        else printf("%d\n",n-2);
    }
    return 0;   
}