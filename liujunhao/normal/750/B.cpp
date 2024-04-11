#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
using namespace std;
typedef long long LL;
typedef pair<int,int>pii;
typedef unsigned uint;
typedef unsigned long long uLL;
const double pi=acos(-1);
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
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
}
//
int n;
int main()
{
	char s[20];
	int len,pos=0;
	Read(n);
	while(n--){
		Read(len);
		scanf("%s",s);
		if(*s=='E'||*s=='W'){
			if(!pos||pos==20000){
				puts("NO");
				return 0;
			}
			continue;
		}
		else if(*s=='S')
			pos+=len;
		else
			pos-=len;
		if(pos<0||pos>20000){
			puts("NO");
			return 0;
		}
	}
	if(!pos)
		puts("YES");
	else
		puts("NO");
}