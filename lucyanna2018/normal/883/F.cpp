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
char s[11111],a[11111];
int la;
int main(){
	int t;
	set<string> ss;
	for(scanf("%d",&t); t--;){
		scanf("%s",s);
		la=0;
		for(int i=0; s[i]; i++)
			if(s[i] == 'u'){
				a[la++] = 'o';
				a[la++] = 'o';
			}else{
				if(s[i] == 'h'){
					while(la>0 && a[la-1] == 'k')
						la--;
				}
				a[la++] = s[i];
			}
		string r = "";
		for(int i=0; i<la; i++)r += a[i];
		ss.insert(r);
	}
	printf("%d\n",ss.size());
	return 0;
}