#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<deque>
#include<stack>
#include<cmath>
#include<ctime>
#include<complex>
#include<list>
#include<limits.h>
using namespace std;

const int N=1e5+5;
int n;
char s[N];
set<int> st;

int main(){
	scanf("%d%s",&n,s+1);
	for(int i=0;i<=9;i++) st.insert(i);
	for(int i=1;i<=n;i++){
		if(s[i]=='L') st.erase(st.begin());
		else if(s[i]=='R'){
			set<int>::iterator it=st.end();
			it--;
			st.erase(it);
		}else st.insert(s[i]-'0');
	}
	for(int i=0;i<=9;i++) if(st.find(i)!=st.end()) printf("0");else printf("1");
	puts("");
	return 0;
}