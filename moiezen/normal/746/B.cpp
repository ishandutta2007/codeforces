#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define rpd(i,r,l) for(int i=r;i>=l;i--)
#define ll long long
#define mo 1000000007
#define N 100005
using namespace std;
int n,l,r;
char str[2005],ans[4005];
int main(){
	scanf("%d%s",&n,str+1);
	l=2001;r=2000;
	if(n&1){
		rpt(i,1,n) if(i&1) ans[++r]=str[i];
		else ans[--l]=str[i];
	}
	else{
		rpt(i,1,n) if(i&1) ans[--l]=str[i];
		else ans[++r]=str[i];
	}
	rpt(i,l,r) printf("%c",ans[i]);
}