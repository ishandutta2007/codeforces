#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n,t;
char s[1<<20];

int main(){
	scanf("%d%d%s",&n,&t,s);
	int i=0;
	for(;s[i]!='.';++i);
	++i;
	while(i<n&&s[i]<'5')++i;
	if(i==n){puts(s);return 0;}
	while(t&&s[i]!='.'+1&&s[i]>='5'){
		s[i-1]++;
		t--;
		i--;
	}
	if(s[i]=='.'+1){
		s[i]=0;i--;
		while(i>=0){
			if(s[i]=='9'){
				s[i]='0';
				i--;
			}
			else {
				s[i]++;
				break;
			}
		}
		if(i<0)putchar('1');
		puts(s);
		return 0;
	}
	s[i+1]=0;
	puts(s);
	return 0;
}