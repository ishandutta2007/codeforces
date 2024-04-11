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

#define ran 1111
int n,fat[ran],cnt[ran];
bool isLeaf[ran];
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)isLeaf[i] = true;
	for(int i=2; i<=n; i++){
		scanf("%d",&fat[i]);
		isLeaf[fat[i]] = false;
	}
	for(int i=2; i<=n; i++)
		if(isLeaf[i])
			cnt[fat[i]] ++;
	for(int i=1; i<=n; i++)if(!isLeaf[i] && cnt[i] <= 2){
		puts("No");
		return 0;
	}
	puts("Yes");
	return 0;
}