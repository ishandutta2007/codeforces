/*#### bits/stdc++.h */
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<deque>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
/*####*/

int n,L,c[33];
int main(){
	scanf("%d%d",&n,&L);
	for(int i=0; i<n; i++)
		scanf("%d",&c[i]);
	for(int i=1; i<n; i++)
		c[i] = min(c[i], c[i-1] * 2);
	long long int res = 0;
	for(int i=1; i<n; i++){
		if((L % (1<<i)) >= (1<<(i-1)))
			res += c[i-1];
		res = min(res, (long long int)c[i]);
	}
	res += (long long int)(L / (1<<(n-1))) * c[n-1];
	printf("%I64d\n",res);
	return 0;
}