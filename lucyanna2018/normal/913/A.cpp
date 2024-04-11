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

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d\n",n >= 30 ? m : m % (1<<n));
	return 0;
}