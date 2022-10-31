#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAXN 100000
using namespace std;
int n,len[MAXN*2+10],nxt[MAXN+10],p[MAXN+10],ans,mxpos[MAXN+10],cnt,l[4],r[4];
char s[MAXN*2+10],T[MAXN+10];
void Read(int &x){
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
			return;
		}
	}
}
void Get_nxt(char *s,int *nxt){
	nxt[0]=-1;
	int i=1,j=0;
	while(i<n){
		if(j==-1||s[i]==s[j])
			nxt[++i]=++j;
		else
			j=nxt[j];
	}
}
void kmp(char *s,char *T,int *nxt){
	int i=0,j=0;
	while(i<n){
		if(j==-1||s[i]==T[j])
			p[++i]=++j;
		else
			j=nxt[j];
	}
}
void read(){
	scanf("%s",s);
	n=strlen(s);
	int i;
	for(i=0;i<n;i++)
		T[i]=s[n-i-1];
	Get_nxt(T,nxt);
	kmp(s,T,nxt);
	s[n*2+1]='#';
	s[n*2+2]='$';
	for(i=n-1;i>=0;i--){
		s[i*2+2]=s[i];
		s[i*2+1]='#';
	}
	s[0]='@';
}
void manacher(){
	int po=1,p=1,i,j;
	for(i=1;i<=n*2;i++){
		if(i<p){
			if(i+len[2*po-i]<p){
				len[i]=len[2*po-i];
				continue;
			}
			else
				len[i]=p-i;
		}
		else
			len[i]=1;
		for(j=len[i];s[i+j]==s[i-j];j++);
		len[i]=j;
		po=i,p=i+j;
	}
}
void solve(){
	int i,t,tt;
	for(i=1;i<=n;i++){
		if(p[i]>p[i-1])
			mxpos[i]=i;
		else
			p[i]=p[i-1],mxpos[i]=mxpos[i-1];
		if((t=2*(len[i*2]/2+(tt=min(p[i-len[i*2]/2],n-i-len[i*2]/2+1)))-1)>ans){
			ans=t;
			if(!tt)
				cnt=1,l[1]=i-len[i*2]/2+1,r[1]=len[i*2]-1;
			else{
				cnt=3;
				l[1]=mxpos[i-len[i*2]/2]-p[i-len[i*2]/2]+1;
				r[1]=tt;
				l[2]=i-len[i*2]/2+1,r[2]=len[i*2]-1;
				l[3]=n-tt+1,r[3]=tt;
			}
		}
	}
}
int main()
{
	read();
	manacher();
	solve();
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
		printf("%d %d\n",l[i],r[i]);
}