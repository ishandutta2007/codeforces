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
#define FORD(i,a) for(int i=a-1; i>=0; i--)

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

int n,k;
priority_queue<int>seats, groups;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    
    cin>>n>>k;
    REP(i,1,n){
    	seats.push(2);
    	seats.push(4);
		seats.push(2);
	}
    REP(i,1,k){
    	int x;
    	cin>>x;
    	groups.push(x);
	}
	
	while(!groups.empty() && !seats.empty()){
		int now = groups.top();
		groups.pop();
		int seat = seats.top();
		seats.pop();
		while(seat == 4 && now <= 2){
			seats.push(2);
			seats.push(1);
			seat = seats.top();
			seats.pop();
		}
		
		//printf("pair %d %d\n",now,seat);
		
		now -= seat;
		
		if(now > 0)groups.push(now);
	}
	
	if(groups.empty())cout << "yes" << endl;
	else cout << "no" << endl;

    return 0;
}