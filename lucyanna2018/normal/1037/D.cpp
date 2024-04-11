#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
#define ran 202222
int n;
vector<int> e[ran];
int a[ran];
int fat[ran];
vector<int> tmp1, tmp2;
bool chk(){
	if(a[1] != 1)return false;
	int tail = 1;
	fat[1] = -1;
	for(int head = 1; head <= n; head ++){
		if(head > tail)return false;
		int cur = a[head];
		tmp1.clear();
		tmp2.clear();
		for(int y : e[cur]){
			if(y != fat[cur])
				tmp1.push_back(y);
		}
		int sz = tmp1.size();
		if(tail + sz > n)return false;
		while(sz--){
			++tail;
			tmp2.push_back(a[tail]);
		}
		sort(tmp1.begin(), tmp1.end());
		sort(tmp2.begin(), tmp2.end());
		if(tmp1 != tmp2)return false;
		for(auto y : tmp2)
			fat[y] = cur;
	}
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=1; i<n; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1; i<=n; i++)scanf("%d",&a[i]);
	puts(chk()?"Yes":"No");
	return 0;
}