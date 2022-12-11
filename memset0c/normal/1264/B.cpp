#include<bits/stdc++.h>
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
template<class T> inline void print(T x,int l,int r){for(int i=l;i<=r;i++)print(x[i]," \n"[i==r]);}
const int N=1e5+10;
int a,b,c,d,p[4];
std::vector<int> res;
void check(int x){
	if(p[x]){
		--p[x];
		res.push_back(x);
	}else{
		return;
	}
	if(x==0)check(x+1);
	if(x==3)check(x-1);
	if(x==1){
		if(p[0])check(x-1);
		else check(x+1);
	}
	if(x==2){
		if(p[3])check(x+1);
		else check(x-1);
	}
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(a),read(b),read(c),read(d);
	if(p[0]=a,p[1]=b,p[2]=c,p[3]=d,res.clear(),check(0),res.size()==a+b+c+d){puts("YES"),print(res,0,res.size()-1);return 0;}
	if(p[0]=a,p[1]=b,p[2]=c,p[3]=d,res.clear(),check(1),res.size()==a+b+c+d){puts("YES"),print(res,0,res.size()-1);return 0;}
	if(p[0]=a,p[1]=b,p[2]=c,p[3]=d,res.clear(),check(2),res.size()==a+b+c+d){puts("YES"),print(res,0,res.size()-1);return 0;}
	if(p[0]=a,p[1]=b,p[2]=c,p[3]=d,res.clear(),check(3),res.size()==a+b+c+d){puts("YES"),print(res,0,res.size()-1);return 0;}
	puts("NO");
}