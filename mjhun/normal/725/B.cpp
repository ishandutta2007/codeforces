#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull n;
char c;
char s[]="fedabc";

int main(){
	while((c=getchar())>='0'&&c<='9')n=n*10+c-'0';
	n--;
	ull k=0;
	if(n%4>1)k=n-2;
	else k=n;
	ull t=n/4*2;
	if(n%2)t++;
	int a=0;
	while(s[a]!=c)a++;
	printf("%I64u\n",t*6+a+1+k);
	return 0;
}