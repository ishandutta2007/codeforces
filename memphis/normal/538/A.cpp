#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
//#include<set>
//#include<map>
#include<queue>
//#include<iostream>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define rev(it,v) for(vector<int>::iterator it=v.begin();it!=v.end();it++)
using namespace std;
#define N 105
#define LL long long
const char b[]={" CODEFORCES"};

char a[N],c[N];
int n,m,e,u;

bool check(){
	rep(i,1,10) if(c[i]!=b[i]) return 0;
	return 1;
}

int main(){
	scanf("%s",a+1);
	n=strlen(a+1);
	m=10;
	if(n<10){puts("NO");return 0;}
	u=n-m;
	rep(i,1,n-u+1){
		e=0;
		rep(j,1,i-1) c[++e]=a[j];
		rep(j,i+u,n) c[++e]=a[j];
		if(check()){puts("YES");return 0;}
	}
	puts("NO");
}