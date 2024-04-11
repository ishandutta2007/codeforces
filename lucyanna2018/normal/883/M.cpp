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
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	printf("%d\n",2*(max(2, (int)labs(x1-x2)+1) + max(2,(int)labs(y1-y2)+1)));
	return 0;
}