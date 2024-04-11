#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

bool isv(char a){
	return a=='A'||a=='E'||a=='I'||a=='O'||a=='U'||a=='Y';
}

char s[128];
int n;

int main(){
	scanf("%s",s);
	n=strlen(s);
	char l=-1;
	int r=0;
	fore(i,0,n){
		if(isv(s[i])){
			r=max(r,i-l);
			l=i;
		}
	}
	r=max(r,n-l);
	printf("%d\n",r);
	return 0;
}