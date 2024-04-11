#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <iomanip>
#include <string>
#include <stack>
#include <cstring>
#include <cstdio>

#define SZ(x) (( (int) x.size() ))

using namespace std;

const int maxN = 100*100*10 + 100;
char act[maxN];
int id[maxN];
bool check[maxN];
bool state[maxN];
long long sum[maxN];
int last[maxN];
int isOff[maxN];
vector<int> ans;

int main()
{
	int n,k;
	cin >> n >> k;
	bool ch = false;
	long long online = 0 ; 

	for(int i = 0 ; i < k ; i++ )
	{
		 cin >> act[i] >> id[i];
		 id[i]--;
		 if( check[id[i]] == 0 ) 
		 {
			 check[id[i]] = 1; 
			 if( act[i] == '-' ) 
				 online++;
		 }
	}
	
	sum[1] = online;
	for(int i = 1 ; i <= k ;i++ ) 
	{
		int ind = id[i-1];
		if( act[i-1] == '+' ) 
		{
			isOff[ind] = 0;
			if( sum[i] - sum[last[ind]] > 0 ) 
				state[ind] = 1;
			online++;
		}
		if( act[i-1] == '-' ) 
		{
			last[ind] = i;
			online--;
			if( online > 0 ||  i != k ) 
				isOff[ind] = 1;
		}
		sum[i+1] = sum[i] + online;
	}

	for(int i = 0 ; i < n ; i++ ) 
		if( state[i] == 0 && ( !isOff[i] || sum[k+1] - sum[last[i]] == 0 )  ) 
			ans.push_back(i);


	cout << SZ( ans ) << endl;
	for(int i =0;i < SZ( ans ) ; i++ ) 
		cout << ans[i] + 1 << ' ';
	cout << endl;
}