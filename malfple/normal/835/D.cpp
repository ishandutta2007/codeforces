#include <iostream>
#include <iomanip>
#include <cstdio>

#include <cstring>
#include <string>
#include <sstream>

#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>

#include <queue>
#include <utility>
#include <set>
#include <stack>
#include <vector>
#include <map>

#define YOU using
#define DONT namespace
#define SAY std

YOU DONT SAY;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define REPP(i,a,b,d) for(int i=a;i<=b;i+=d)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,d) for(int i=a;i>=b;i-=d)
#define REV(i,a,b) REVV(i,a,b,1)

#define FOR(i,a) for(int i=0; i<a; i++)
#define FORD(i,a) for(int i=(int)a-1; i>=0; i--)

#define mp make_pair

#define pb push_back
#define ff first
#define ss second

const int OO = 1e9;
const ll INF = 1e18;

const int irand(int lo,int hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

const ll lrand(ll lo,ll hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

//end of macro

typedef unsigned long long ull;

const int N = 5005;
const int P = 13;

string str;
ull hashs[N][N];
bool palin[2][N][N];
int ans[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    
    cin>>str;
	
	//construct palin
	FOR(k,str.size()){
		for(int i=k, j=k; i>=0 && j<str.size(); i--,j++){
			if(str[i] == str[j]){
				palin[1][i][j] = true;
				ans[1]++;
			}else break;
		}
		
		for(int i=k, j=k+1; i>=0 && j<str.size(); i--,j++){
			if(str[i] == str[j]){
				palin[1][i][j] = true;
				ans[1]++;
			}else break;
		}
	}
	
	//construct the rest
	int next = 0;
	int prev = 1;
	REP(p,2,P){
		memset(palin[next], false ,sizeof palin[next]);
		
		int shortest = (1<<(p-1));
		REP(s,shortest,str.size()){
			REP(i,0,(int)str.size()-s){
				int half = s/2;
				if(palin[prev][i][i+half-1] && palin[prev][i][i+s-1]){
					palin[next][i][i+s-1] = true;
					ans[p]++;
				}
			}
		}
		
		next ^= 1;
		prev ^= 1;
	}
	
	FOR(i,str.size())cout << ans[i+1] << " ";
	cout << endl;

    return 0;
}