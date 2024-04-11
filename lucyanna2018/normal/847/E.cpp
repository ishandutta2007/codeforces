#include<stdio.h>
#include<set>
using namespace std;
int n;
char s[111111];
int pos[111111],lp;
set<int> star;
bool ok(int L){
	int prev = -1;
	for(int i=0; i<lp; i++){
		set<int>::iterator it = star.upper_bound(prev);
		if(it == star.end())return true;
		int d = pos[i] - (*it);
		if(d > L)return false;
		if(d > 0)
			prev = pos[i]+max((L-d)/2, L-2*d);
		else
			prev = pos[i]+L;
	}
	return prev >= *star.rbegin();
}
int main(){
	scanf("%d%s",&n,s+1);
	for(int i=1; i<=n; i++)
		if(s[i] == 'P'){
			pos[lp++] = i;
		}else
		if(s[i] == '*')
			star.insert(i);

	int lo = 1, hi = 2*n;
	while(lo != hi){
		int mi = (lo+hi)/2;
		if(ok(mi))
			hi = mi;
		else
			lo = mi+1;
	}
	printf("%d\n",lo);
	return 0;
}