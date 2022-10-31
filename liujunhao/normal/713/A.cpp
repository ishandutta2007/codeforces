#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
template<class T>
void Read(T &x){
	static char c;
	bool f(0);
	while(c=getchar(),c!=EOF)
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
}
map<long long,int>cnt;
int T;
int main()
{
	Read(T);
	char s[20];
	long long a,b,base;
	int i;
	while(T--){
		scanf("%s",s);
		if(*s=='+'||*s=='-'){
			Read(a);
			base=1;
			b=0;
			for(i=0;i<18;i++,base*=10)
				b+=((a/base)&1)*base;
			if(*s=='+')
				cnt[b]++;
			else
				cnt[b]--;
		}
		else{
			Read(b);
			printf("%d\n",cnt[b]);
		}
	}
}