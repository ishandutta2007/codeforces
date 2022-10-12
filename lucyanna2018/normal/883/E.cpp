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
int mask;
char s[1111],c[1111];
int l;
int chk(char *c){
	int mm = 0;
	for(int i=0; i<l; i++)if(islower(s[i])){
		if(c[i] != s[i])return -1;
	}else{
		int x = c[i] -'a';
		if(mask&(1<<x))return -1;
		mm |= 1<<x;
	}
	return mm;
}
int main(){
	int n;
	scanf("%d%s%d",&l,s,&n);
	for(int i=0; i<l; i++)if(islower(s[i]))mask |= 1<<(s[i]-'a');
	int mask2 = (1<<26) - 1;
	while(n--){
		scanf("%s",c);
		int r = chk(c);
		if(r >= 0)mask2 &= r;
	}
	int r=0;
	for(int i=0; i<26; i++)if(mask2&(1<<i))r++;
	printf("%d\n",r);
	return 0;
}