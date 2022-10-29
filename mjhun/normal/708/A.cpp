#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n;
char s[100005];

int main(){
	scanf("%s",s);
	n=strlen(s);
	bool w=true;
	fore(i,0,n)if(s[i]!='a')w=false;
	if(w){
		fore(i,0,n-1)putchar('a');
		putchar('z');
		puts("");
	}
	else {
		int i=0;
		while(s[i]=='a')i++;
		while(i<n&&s[i]>'a'){
			s[i]--;
			i++;
		}
		puts(s);
	}
	return 0;
}