#include<bits/stdc++.h>
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
const int N=1e5+7;
int n,m,ans,lenf=1,leng=1;
int x[N],y[N],g[N],f[N],fl[N],fl2[N],len[N];
std::vector<int>vet[N];
inline void getq(int u){
	for(int i=0;i<len[u];i++)if((--fl[vet[u][i]])==1)f[++f[0]]=vet[u][i];
}
inline void push(int c){
	if(!fl2[x[c]])fl2[x[c]]=1,getq(x[c]);
	if(!fl2[y[c]])fl2[y[c]]=1,getq(y[c]);
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n),read(m);
	for(int i=1;i<=m;i++)read(x[i]),read(y[i]);
	for(int i=1;i<=m;i++){
		fl[i]=2,g[++g[0]]=i;
		vet[x[i]].push_back(i),len[x[i]]++;
		vet[y[i]].push_back(i),len[y[i]]++;
	}
	for(bool flag=true,tag;flag;){
		flag=tag=false;
		if(!flag){
			while(lenf<=f[0]){
				if(fl[f[lenf]]==1){tag=1,push(f[lenf]),lenf++; break;}
				else lenf++;
			}
			if(tag)ans++,flag=true;
		}
		if(!flag){
			while(leng<=g[0]){
				if(fl[g[leng]]==2){tag=1,push(g[leng]),leng++;break;}
				else leng++;
			}
			if(tag)ans++,flag=true;
		}
	}
	print(m-ans,'\n');
}