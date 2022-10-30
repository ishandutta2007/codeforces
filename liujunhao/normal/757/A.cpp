#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<ext/pb_ds/priority_queue.hpp>  
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
#define MAXN 100000
char s[MAXN+10];
int cnt[256];
int main()
{
	scanf("%s",s);
	for(int i=0;s[i];i++)
		cnt[s[i]]++;
	printf("%d\n",min(cnt['B'],min(cnt['u']/2,min(cnt['l'],min(cnt['b'],min(cnt['a']/2,min(cnt['s'],cnt['r'])))))));
}