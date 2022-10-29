#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

char s[1024];

int main(){
	int n;
	scanf("%d",&n);gets(s);
	int ta=(1<<30),r=0,q=0;
	fore(i,0,n){
		int h,m;char c;
		scanf("[%d:%d %c.m.]",&h,&m,&c);
		gets(s);
		h%=12;
		int t=h*61+m;
		if(c=='p')t+=(1<<20);
		if(t<ta)r++;
		if(t==ta){
			q++;
			if(q==11){r++;q=1;}
		}
		else q=1;
		ta=t;
	}
	printf("%d\n",r);
	return 0;
}