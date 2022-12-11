#include<bits/stdc++.h>
const int S=1<<21; char ibuf[S],*iS,*iT,obuf[S],*oS=obuf,*oT=oS+S-1;
#define flush() (fwrite(obuf,1,oS-obuf,stdout),oS=obuf,void())
#define getchar() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,S,stdin),(iS==iT?EOF:*iS++)):*iS++)
#define putchar(x) (*oS++=(x),oS==oT?flush():void())
struct Flusher_{~Flusher_(){flush();}}flusher_;
template<class T> inline void read(T &x){
	x=0; register char c=getchar(); register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
template<class T> inline void readchar(T &x){
	x=getchar();
	while(!isalpha(x))x=getchar();
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10); putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
const int N=2e5+10,sqn=600;
int n,m,k,ans,cnt,a[N],b[N],s[N];
struct sequence{
	int siz,ans;
	std::vector<int> vec,bln,tag;
	std::vector<std::array<short,(1<<14)>> val;
	inline int left(int k){return k*sqn;}
	inline int right(int k){return std::min((int)vec.size()-1,(k+1)*sqn-1);}
	void modify(int k,int x){
		::ans+=ans,cnt-=(vec.back()^tag.back())!=0;
		// printf("modify %d %d : %d %d %d\n",k,x,bln[k],left(bln[k]),right(bln[k]));
		for(int i=bln[k]+1;i<=bln.back();i++){
			ans-=val[i][tag[i]];
			tag[i]^=x;
			ans+=val[i][tag[i]];
		}
		if(bln.back())for(int i=left(bln[k]);i<=right(bln[k]);i++)val[bln[k]][vec[i]]--;
		for(int i=k;i<=right(bln[k]);i++){
			ans-=vec[i]==tag[bln[k]];
			vec[i]^=x;
			ans+=vec[i]==tag[bln[k]];
		}
		if(bln.back())for(int i=left(bln[k]);i<=right(bln[k]);i++)val[bln[k]][vec[i]]++;
		::ans-=ans,cnt+=(vec.back()^tag.back())!=0;
	}
	void init(){
		// printf("vec=");for(int i=0;i<vec.size();i++)printf("%d%c",vec[i],",\n"[i+1==vec.size()]);
		for(int i=1;i<vec.size();i++)vec[i]^=vec[i-1];
		for(int i=0;i<vec.size();i++)ans+=vec[i]==0;
		for(int i=0;i<vec.size();i++)bln.push_back(i/sqn);
		tag.resize(bln.back()+1);
		if(bln.back()){
			val.resize(bln.back()+1);
			for(int k=0;k<=bln.back();k++){
				for(int i=left(k);i<=right(k);i++)val[k][vec[i]]++;
			}
		}
		::ans+=vec.size()-ans,cnt+=(vec.back()^tag.back())!=0;
	}
}f[N];
void output(){print(cnt?-1:ans,'\n');}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n),read(k),read(m);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++)read(b[i]);
	for(int i=1;i<=n+1;i++)s[i]=a[i-1]^b[i-1]^a[i]^b[i];
	// for(int i=1;i<=n+1;i++)printf("%d%c",s[i]," \n"[i==n+1]);
	for(int i=1;i<=n+1;i++)f[(i-1)%k].vec.push_back(s[i]);
	for(int i=0;i<k;i++)f[i].init();
	output();
	for(int c,p,x,v,i=1;i<=m;i++){
		readchar(c),read(p),read(x);
		// printf("> %c %d %d\n",c,p,x);
		if(c=='a')v=a[p]^x,a[p]=x;
		if(c=='b')v=b[p]^x,b[p]=x;
		f[p%k].modify(p/k,v);
		f[(p-1)%k].modify((p-1)/k,v);
		output();
	}
}