#include <algorithm>
#include <cassert>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define INF 0x3f3f3f3f
#define INFLL 100000000000000000ll
#define gc getchar()
#define abs(x) ((x)>0?(x):(-(x)))
#define X first
#define Y second
#define mp(x,y) make_pair((x),(y))
#define eps (1e-8)
#define pb push_back
#define pf(x) ((x)*(x))
#define il inline

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;

il ll read()
{
	char c=gc;ll u=0,f=1;
	while(c!='-' && (c<'0' || '9'<c))c=gc;
	if(c=='-'){
		f=-1;
		c=gc;
	}
	while('0'<=c && c<='9'){
		u=u*10+c-'0';
		c=gc;
	}
	return u*f;
}
il char readc()
{
	for(;;){
		char c=gc;
		if('A'<=c && c<='Z' || 'a'<=c && c<='z')return c;
	}
}
il int read_digit()
{
	for(;;){
		char c=gc;
		if('0'<=c && c<='9')return c-'0';
	}
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
template <typename T>inline void updmax(T &a,T b){if(b>a)a=b;}
template <typename T>inline void updmin(T &a,T b){if(b<a)a=b;}
inline void swap(int &a,int &b){int t=a;a=b;b=t;}

inline void fileio(string s){
	if(s=="txt"){
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}
	else{
		freopen((s+".in").c_str(),"r",stdin);
		freopen((s+".out").c_str(),"w",stdout);
	}
}

void put(int a,int b)
{
    putchar(char(a+'a'-1));
    putchar(char(b+'1'-1));
    putchar(' ');
}

void work(int n){
    int x=1,y=1,dir=1;
    put(1,1);
    for(int i=1;i<=n-3;i++){
        if(y+dir>8 || y+dir<1){
            dir=-dir;
            x++;
        }
        else y+=dir;
        put(x,y);
    }
    if(y!=8)put(8,y);
    else put(7,8);
    put(8,8);
}


int main()
{
    int n=read();n++;
    if(n<=57)work(n);
    else{
        for(int i=1;i<=6;i++){
            int st,ed,dir;
            if(i%2==1){
                st=1;ed=9;dir=1;
            }
            else{
                st=8;ed=0;dir=-1;
            }
            for(int j=st;j!=ed;j+=dir){
                put(i,j);
            }
        }
        int m=n-48;
        int x,y,dir;
        if(n==64)x=9,y=1,dir=-1;
        else x=6,y=1,dir=1;
        for(int j=1;j<=m-2;j++){
            if(x+dir>8 || x+dir<7){
                y++;
                dir=-dir;
            }
            else x+=dir;
            put(x,y);
        }
        if(x==8){
            put(8,7);
            put(8,8);
        }
        else{
            put(7,8);
            put(8,8);
        }
    }
    return 0;
}