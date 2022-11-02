#include<cstdio>
#include<cstring>
const int Z=26;
const int N=205;
char s[N];
int cnt[Z];
int n,k;
inline int Read(){
	char ch;
	int f=1;
	while((ch=getchar())<'0'||ch>'9')
		if(ch=='-') f=-1;
	int x=ch^48;
	while((ch=getchar())>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
inline void Init(){
	n=Read(),k=Read();
	memset(cnt,0,sizeof(cnt));
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		cnt[s[i]-'a']++;
	return ;
}
inline void Solve(){
	for(int i=1;i<=k;i++){
		char ch='z';
		if(n/k<=25) ch='a'+n/k;
		for(int j=0;j<Z&&j<n/k;j++){
			if(!cnt[j]){
				ch=j+'a';
				break ;
			}
			cnt[j]--;
		}
		putchar(ch);
	}
	putchar('\n');
	return ;
}
int T;
int main(){
	for(T=Read();T;T--){
		Init();
		Solve();
	}
	return 0;
}