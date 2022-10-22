#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
using namespace std;
typedef long long ll;
char s[10];
int x;
int main(){
	scanf("%s",s);
	scanf("%d",&x);
	/*
	if(s[0]=='A'&&s[1]=='B'&&s[2]=='C'&&x==0){
		puts("YES");
		return 0;
	}
	if(s[0]=='A'&&s[1]=='R'&&s[2]=='C'&&x==0){
		puts("YES");
		return 0;
	}
	if(s[0]=='A'&&s[1]=='G'&&s[2]=='C'&&x==0){
		puts("NO");
		return 0;
	}
	if(s[0]=='A'&&s[1]=='B'&&s[2]=='C'){
		assert(x>248);
	}
	if(s[0]=='A'&&s[1]=='R'&&s[2]=='C'){
		assert(x>138);
	}
	if(s[0]=='A'&&s[1]=='G'&&s[2]=='C'){
		assert(x>56);
		assert(x>55);
	}
	*/
	//assert(x==0);
	//assert(s[1]=='G');
	if(s[0]=='A'&&s[2]=='C'){
		if(s[1]=='B'&&x<2000 || s[1]=='R'&&x<2800 || s[1]=='G'&&x>=1200) puts("YES");
		else puts("NO");
	}else puts("NO"),assert(0);
	return 0;
}