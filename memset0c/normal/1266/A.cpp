#include<bits/stdc++.h>
#define ll long long 
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
const int N=1e5+10,mod=998244353;
int T,n,tot,tag1,tag2;
std::string str;
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	for(read(T);T--;){
		std::cin>>str,n=str.size(),tot=tag1=tag2=0;
		for (int i=0;i<n;i++){
			tot=(tot+str[i])%3;
			if((str[i]-'0')%2==0)tag2++;
			if(str[i]=='0')tag1=1;
		}
		printf((tag1&&tag2>=2&&!tot)?"red\n":"cyan\n");
	}
}