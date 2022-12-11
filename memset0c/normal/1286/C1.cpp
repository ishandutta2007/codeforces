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
template<class T> inline void print(T a,int l,int r){for(int i=l;i<=r;i++)print(a[i]," \n"[i==r]);}
const int N=110;
int n,m,ans[N];
struct atom{
	int a[26];
	inline int length()const{
		int s=0;
		for(int i=0;i<26;i++)s+=a[i];
		return s;
	}
	inline bool operator<(const atom &other)const{
		for(int i=0;i<26;i++){
			if(a[i]!=other.a[i])return a[i]<other.a[i];
		}
		return false;
	}
}res[N];
std::map<atom,int> map;
inline atom operator-(const atom &a,const atom &b){
	atom c;
	for(int i=0;i<26;i++)c.a[i]=a.a[i]-b.a[i];
	return c;
}
inline void read(atom &x){
	std::string s;
	std::cin>>s;
	for(int i=0;i<s.length();i++)x.a[s[i]-'a']++;
}
std::vector<atom> ask(int l,int r){
	printf("? %d %d\n",l,r);
	std::vector<atom> res((r-l+1)*(r-l+2)/2);
	for(int i=0;i<res.size();i++)read(res[i]);
	return res;
}
int main(){
#ifdef memset0
	// freopen("1.in","r",stdin);
#endif
	read(n);
	if(n==1){
		printf("? 1 1\n");
		std::string s;
		std::cin>>s;
		std::cout<<"! "<<s<<std::endl;
		return 0;
	}
	auto S=ask(1,n),A=ask(1,1),B=ask(2,n);
	for(auto it:S)map[it]++;
	for(auto it:A)map[it]--;
	for(auto it:B)map[it]--;
	res[1]=A[0];
	for(auto it:map)if(it.second){
		res[it.first.length()]=it.first;
		// printf(">> %d %d\n",it.first.length(),it.second);
	}
	for(int i=n;i>=1;i--){
		res[i]=res[i]-res[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++)if(res[i].a[j]){
			ans[i]=j;
		}
	}
	printf("! ");
	for(int i=1;i<=n;i++)putchar(ans[i]+'a');
}