/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

const int maxN= 100000+5;

int n,k;
int dp[maxN][30], DP[maxN][30];
string s;

inline void setDyn(){
	for (int i=0;i<26;i++)
		dp[0][i]= -1;
	dp[0][s[0]-'a']= 0;
	for (int i=1;i< (int)s.size();i ++){
		for (int j=0;j< 26;j ++)
			dp[i][j]= dp[i-1][j];
		dp[i][s[i]-'a']= i;
	}	
	int tmp= (int)s.size()-1;
	for (int i=0;i<26;i ++)
		DP[tmp][i]= -1;
	DP[tmp][s[tmp]-'a']= tmp;
	for (int i=(int)s.size()-2;i>=0;i --){
		for (int j=0;j< 26;j ++)
			DP[i][j]= DP[i+1][j];
		DP[i][s[i]-'a']= i;
	}
}
/************************************/
inline void check (string &v){
	int SIZE= (int)s.size();
	long long ret=0;
	for (int i=0;i< (int)v.size();i ++){
		int poi= (SIZE<=i) ? SIZE-1 : i;
		int a1= dp[poi][v[i]-'a'], a2= DP[poi][v[i]-'a'];
		int res= (int)v.size();
		if (a1!=-1)
			res= min(res,i-a1);
		if (a2!=-1){
			if (a1!=-1)
				res= min (res, max(a2-i, i-a2));
			else
				res= max (a2-i, i-a2);
		}
		ret+= res;
	}
	cout << ret << endl;
}
/************************************/
int main(){
	cin >> n >> k;
	for (int i=1;i<=k;i ++){
		char tmp;
		cin >> tmp;
		s+= tmp;
	}
	setDyn();
	while (n>0){
		string tmp;
		cin >> tmp;
		check (tmp);
		n--;
	}
	return 0;
}