#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e6+5;
int n,m;
char s[MAXN],s2[MAXN];
int w[MAXN];
void Manacher(){
	s2[m+1]='#';
	s2[m+2]=0;
	int r=-1,mid=-1;
	for(int i=1;i<=m;i++){
		if(i<r) w[i]=min(w[(mid<<1)-i],r-i);
		else w[i]=1;
		while(s2[i-w[i]]==s2[i+w[i]])
			w[i]++;
		if(w[i]+i>r)
			r=w[i]+i,mid=i;
	}
	return ;
}
int main(){
	//freopen("in1.txt","r",stdin);
	int t; scanf("%d",&t);
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);
		int v=0;
		while(v+1<(n+1>>1))
			if(s[v+1]==s[n-v]) v++;
			else break;
		s2[m=1]='#';
		for(int i=v+1;i<=n-v;i++)
			s2[++m]=s[i],s2[++m]='#';
		Manacher();
		int mx=0;
		for(int i=1; i<=m; i++){
			if(w[i]==i) mx=max(mx,w[i]);
			if(i+w[i]==m+1) mx=max(mx,w[i]);
		}
		//puts(s2+1);
		//for(int i=1; i<=m; i++)
			//printf("w %d %d\n",i,w[i]);
		for(int i=1; i<=m; i++)
			if(w[i]==mx&&(w[i]==i||i+w[i]==m+1)){
				//printf("i %d\n",i);
				//printf("mx %d\n",mx);
				for(int j=1; j<=v; j++) putchar(s[j]);
				for(int j=i-w[i]+2;j<=i+w[i]-2;j+=2) putchar(s2[j]);
				for(int j=n-v+1;j<=n;j++) putchar(s[j]);
				break;
			}
		puts("");
	}
	return 0;
}