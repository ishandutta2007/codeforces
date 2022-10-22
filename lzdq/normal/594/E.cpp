// fuck luogu
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<random>
#include<chrono>
using namespace std;
typedef long long ll;
const int MAXN=5e6+5;
int n,k;
char s[MAXN*2];
struct Lyndon{
	int l,d,c;
}ld[MAXN];
int tot;
string ans,mi;
void MinExp(){
	for(int i=1; i<=n; i++)
		s[i+n]=s[i];
	int w;
	s[n*2+1]=0;
	for(int i=1; i<=n*2; ){
		int j=i,k=i+1;
		while(k<=n*2){
			if(s[k]<s[j]) break;
			if(s[k]>s[j]) j=i;
			else j++;
			k++;
		}
		while(i<=j){
			if(i<=n) w=i;
			i+=k-j;
		}
	}
	//printf("MinExp w %d\n",w);
	mi=min(mi,string(s+w,s+w+n));
	return ;
}
int a[MAXN],b[MAXN];
void exkmp(){
	s[n+1]=0;
	for(int i=2,r=0,w=0; i<=n; i++){
		if(i<=r) a[i]=min(r-i+1,a[i-w+1]);
		while(s[i+a[i]]==s[1+a[i]]) a[i]++;
		if(a[i]&&i+a[i]-1>r){
			r=i+a[i]-1;
			w=i;
		}
	}
	for(int i=1,r=0,w=0; i<=n; i++){
		if(i<=r) b[i]=min(r-i+1,a[i-w+1]);
		while(s[n+1-(i+b[i])]==s[1+b[i]]) b[i]++;
		if(b[i]&&i+b[i]-1>r){
			r=i+b[i]-1;
			w=i;
		}
	}
	return ;
}
bool vis[MAXN];
int kmp[MAXN];
void SolveLR(){
	int pos;
	s[n+1]='z'+1;
	s[n+2]=0;
	for(int i=1; i<=n+1; ){
		int j=i,k=i+1;
		while(k<=n+1){
			if(s[k]<s[j]) break;
			if(s[k]>s[j]) j=i;
			else j++;
			k++;
		}
		while(i<=j){
			pos=i;
			i+=k-j;
		}
	}
	s[n+1]=0;
	for(int i=n-1,j=0; i>=pos; i--){
		while(j&&s[i]!=s[n-j]) j=kmp[n+1-j];
		if(s[i]==s[n-j]) j++;
		kmp[i]=j;
	}
	int w=pos;
	while(w<=n){
		vis[n-w+1]=1;
		w=n-kmp[w]+1;
	}
	for(int k=0; 1<<k<=n; k++){
		int x=0,y=0;
		for(int i=1<<k; i<min(1<<k+1,n+1); i++)
			if(vis[i]){
				if(!x) x=i;
				y=i;
			}
		if(x){
			string t(s+n+1-y,s+n+1);
			for(int i=n-y; i; i--)
				t+=s[i];
			mi=min(mi,t);
			t=string(s+n+1-x,s+n+1);
			for(int i=n-x; i; i--)
				t+=s[i];
			mi=min(mi,t);
		}
	}
	return ;
}
void SolveRL(){
	int pos=0;
	for(int i=1; i<=n; i++){
		int d=b[n+1-i];
		bool ok=0;
		if(d>=i-pos){
			d=a[i-pos+1];
			if(d<pos&&s[1+d]>s[i-pos+1+d]) ok=1;
		}else if(s[i-d]>s[1+d]) ok=1;
		if(ok) pos=i;
	}
	string res;
	for(int i=n; i>pos; i--)
		res+=s[i];
	res+=string(s+1,s+pos+1);
	mi=min(mi,res);
	//printf("SolveRL pos %d %s\n",pos,res.c_str());
	return ;
}
int main(){
	//freopen("in","r",stdin);
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%d",&k);
	if(k==1){
		ans=string(s+1,s+n+1);
		reverse(s+1,s+n+1);
		ans=min(ans,string(s+1,s+n+1));
	}else{
		reverse(s+1,s+n+1);
		for(int i=1; i<=n; ){
			int j=i,k=i+1;
			while(k<=n){
				if(s[k]<s[j]) break;
				if(s[k]>s[j]) j=i;
				else j++;
				k++;
			}
			tot++;
			ld[tot].l=i;
			ld[tot].d=k-j;
			while(i<=j){
				i+=k-j;
				ld[tot].c++;
			}
		}
		while(k>=3){
			if(!tot) break;
			if(ld[tot].d==1){
				while(tot&&ld[tot].d==1){
					for(int i=ld[tot].l; i<ld[tot].l+ld[tot].c; i++)
						ans+=s[i];
					tot--;
				}
			}else{
				for(int i=ld[tot].l; i<ld[tot].l+ld[tot].c*ld[tot].d; i++)
					ans+=s[i];
				tot--;
			}
			k--;
		}
		if(tot){
			n=ld[tot].l+ld[tot].c*ld[tot].d-1;
			//printf("n %d\n",n);
			for(int i=n; i; i--)
				mi+=s[i];
			MinExp();
			exkmp();
			SolveRL();
			SolveLR();
			ans+=mi;
		}
	}
	printf("%s\n",ans.c_str());
	return 0;
}