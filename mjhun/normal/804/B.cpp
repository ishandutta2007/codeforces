#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define MOD 1000000007
using namespace std;
typedef long long ll;

char s[1<<20];
int n;

int main(){
	scanf("%s",s);n=strlen(s);
	int b=0,r=0;
	for(int i=n-1;i>=0;--i){
		if(s[i]=='a'){
			r+=b;r%=MOD;
			b*=2;b%=MOD;
		}
		else {
			b++;
			b%=MOD;
		}
	}
	printf("%d\n",r);
	return 0;
}