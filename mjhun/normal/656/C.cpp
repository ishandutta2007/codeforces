#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

char s[64];
int n;

int main(){
	scanf("%s",s);n=strlen(s);
	int r=0;
	fore(i,0,n){
		int k=tolower(s[i])-'a'+1;
		r+=('@'<s[i]&&'['>s[i])*k-('`'<s[i]&&'{'>s[i])*k;
	}
	printf("%d\n",r);
	return 0;
}