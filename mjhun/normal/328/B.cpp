#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int get(char c){
	c-='0';
	if(c==5)c=2;
	if(c==9)c=6;
	return c;
}

char t[256],s[256];
int qt[16],qs[16];

int main(){
	scanf("%s%s",t,s);
	for(int i=0;t[i];++i)qt[get(t[i])]++;
	for(int i=0;s[i];++i)qs[get(s[i])]++;
	int r=1005;
	fore(i,0,10)if(qt[i])r=min(r,qs[i]/qt[i]);
	printf("%d\n",r);
	return 0;
}