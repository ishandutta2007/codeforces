#include<cstdio>
#include<algorithm>
using namespace std;
long long a,b,c,l,ans;
void Read(long long &x){
	char c;
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
long long f(int a,int b,int c){
	int i,t;
	long long ret=0;
	for(i=0;i<=l;i++){
		t=min(1ll*c+i-a-b,l-i);
		if(t>=0)
		ret+=1ll*(t+1)*(t+2)/2;
	}
	return ret;
}
int main()
{
	Read(a),Read(b),Read(c),Read(l);
	int i;
	for(i=0;i<=l;i++)
		ans+=1ll*(i+1)*(i+2)/2;
	ans-=f(a,b,c)+f(b,c,a)+f(a,c,b);
	printf("%I64d\n",ans);
}