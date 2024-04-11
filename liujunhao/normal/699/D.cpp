#include<cstdio>
#include<algorithm>
#define MAXN 200000
using namespace std;
template<class T>
void Read(T &x){
	static char c;
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
int n,p[MAXN+10],r,cnt,fa[MAXN+10];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main()
{
	Read(n);
	int i;
	for(i=1;i<=n;i++){
		Read(p[i]),fa[i]=i;
		if(p[i]==i&&!r)
			r=i;
	}
	for(i=1;i<=n;i++)
		if(p[i]==i&&(!r||i==r)){
			r=i;
		}
		else{
			if(p[i]==i){
				p[i]=r;
				cnt++;
			}
			else{
				if(find(i)!=find(p[i])){
					fa[fa[i]]=fa[p[i]];
				}
				else{
					if(!r)
						r=i;
					p[i]=r,fa[fa[i]]=fa[r];
					cnt++;
				}
			}
		}
	printf("%d\n",cnt);
	for(i=1;i<n;i++)
		printf("%d ",p[i]);
	printf("%d\n",p[n]);
}