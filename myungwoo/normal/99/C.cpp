#include <stdio.h>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int A[]={0,1,2,3,4,5},R1[]={0,2,5,4},R2[]={1,2,3,4},R3[]={0,3,5,1};
string str;
char buf[9];
set <string> V;

string rt(int R[],string s)
{
	string ret=s;
	for (int i=0;i<4;i++) ret[R[(i+1)%4]] = s[R[i]];
	return ret;
}

bool dfs(string s,int a,int b,int c)
{
	if (V.find(s) != V.end()) return 1;
	if (a < 3 && dfs(rt(R1,s),a+1,b,c) || b < 3 && dfs(rt(R2,s),a,b+1,c) || c < 3 && dfs(rt(R3,s),a,b,c+1)) return 1;
	return 0;
}

int main()
{
	scanf("%s",buf);
	do{
		str = "";
		for (int i=0;i<6;i++) str += buf[A[i]];
		if (!dfs(str,0,0,0)) V.insert(str);
	} while(next_permutation(A,A+6));
	printf("%d",V.size());
}