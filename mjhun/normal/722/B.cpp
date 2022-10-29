#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

bool isv(char c){
	return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y';
}

int nl;
int p[128];
char s[128];

int main(){
	scanf("%d",&nl);
	fore(i,0,nl)scanf("%d",p+i);gets(s);
	bool r=true;
	fore(i,0,nl){
		gets(s);
		int nv=0;
		for(int j=0;s[j];++j){
			nv+=isv(s[j]);
		}
		if(nv!=p[i])r=false;
	}
	puts(r?"YES":"NO");
	return 0;
}