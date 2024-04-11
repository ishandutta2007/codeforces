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
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN= 1000*1000+5;

char s[MAXN];
int len, vMax= 0, wMax= 1;
int dp[MAXN], way[MAXN];

inline void setDyn (){
	for (int i= 2;s[i]!= 0;i ++){
		if (s[i]== '(')
			continue;

		if (s[(i-1)-dp[i-1]]== '(')
			dp[i]= dp[i-1]+ 2;
		dp[i]+= dp[i-dp[i]];
		way[dp[i]] ++;
	}
	way[0]= 1;
}
/***********************************/
int main (){
	gets (&s[1]);
	setDyn ();
	for (int i= strlen (&s[1]);i>= 0;i --)
		if (way[i]){
			cout << i << ' ' << way[i] << endl;
			break;
		}

	return 0;
}