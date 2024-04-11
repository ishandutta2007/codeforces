#include<cstring>
#include<cstdio>
using namespace std;
const int MAXL = 1e5+5;
struct BigNum {
	int len,s[MAXL];
	BigNum operator =(const char *num) {
		len=strlen(num);
		for (int i=0; i<len; i++)
			s[i]=num[len-i-1]-'0';
		return *this;
	}
	BigNum operator +(const BigNum &b) {
		BigNum c;
		c.len=0;
		for (int i=0,g=0; g||i<len||i<b.len; i++) {
			int x=g;
			if (i<len) x+=s[i];
			if (i<b.len) x+=b.s[i];
			c.s[c.len++]=x%10;
			g=x/10;
		}
		return c;
	}
	bool operator <(const BigNum &b) {
		if (len!=b.len) return len<b.len;
		for (int i=len-1; i>=0; i--)
			if (s[i]!=b.s[i]) return s[i]<b.s[i];
		return 1;
	}
	void print(){
		for(int i=len-1;i>=0;i--)
			putchar(s[i]+'0');
		puts("");
		return ;
	}
}a,b,ans;
int l;
char str[MAXL];
int main() {
	scanf("%d%s",&l,str+1);
	ans.len=MAXL-2;
	for(int i=(l>>1)+1;i<=l;i++){
		if(str[i]=='0') continue ;
		b=str+i;
		char t=str[i];
		str[i]=0;
		a=str+1;
		str[i]=t;
		a=a+b;
//		a.print(),b.print();
		if(a<ans) ans=a;
		break;
	}
	for(int i=(l>>1)+2;i>1;i--){
		if(str[i]=='0') continue ;
		b=str+i;
		char t=str[i];
		str[i]=0;
		a=str+1;
		str[i]=t;
		a=a+b;
//		a.print(),b.print();
		if(a<ans) ans=a;
		break;
	}
	ans.print();
	return 0;
}