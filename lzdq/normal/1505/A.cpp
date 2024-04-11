#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
char s[MAXN];
int main(){
	//freopen("in1.txt","r",stdin);
	while(cin.getline(s,MAXN)){
		if(memcmp(s,"Is it rated?",strlen(s))==0) puts("NO");
		else puts("YES");
		fflush(stdout);
	}
	return 0;
}