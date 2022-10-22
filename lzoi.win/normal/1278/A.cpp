#include<cstdio>
#include<cstring>
const int N=105;
const int Z=26;
char s[N],ss[N];
int Cnt[Z],Cnt_[Z],len,T;
inline void Copy(){
	for(register int i=0;i<Z;i++)
		Cnt_[i]=Cnt[i];
}
inline void Query(){
	for(register int i=0;ss[i+len-1];i++){
		Copy();
		bool flag=1;
		for(register int j=0;j<len;j++){
			int k=i+j;
			int p=ss[k]-'a';
			if(!Cnt_[p]){
				flag=0;
				break ;
			}
			Cnt_[p]--;
		}
		if(flag) return puts("YES"),void();
	}
	puts("NO");
}
inline void Init(){
	memset(Cnt,0,sizeof(Cnt));
	scanf("%s",s);
	len=0;
	for(register int i=0;s[i];i++){
		int p=s[i]-'a';
		Cnt[p]++;
		len++;
	}
	scanf("%s",ss);
}
int main(){
	for(scanf("%d",&T);T;T--){
		Init();
		Query();
	}
	return 0;
}