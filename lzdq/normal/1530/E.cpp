#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n;
char s[MAXN],t[MAXN];
int cnt[30];
int main(){
	//freopen("in","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%s",s+1);
		n=strlen(s+1);
		memset(cnt,0,sizeof(cnt));
		char mi='z';
		for(int i=1; i<=n; i++){
			cnt[s[i]-'a']++;
			mi=min(mi,s[i]);
		}
		int c=cnt[mi-'a'];
		if(c==n){
			puts(s+1);
			continue;
		}
		sort(s+1,s+n+1);
		int x=0;
		for(int i=0; i<26; i++)
			if(cnt[i]==1){
				x=i+'a';
				break;
			}
		if(x){
			for(int i=1; i<=n; i++)
				if(s[i]==x){
					x=i;
					break;
				}
			putchar(s[x]);
			s[x]=0;
			printf("%s",s+1);
			puts(s+x+1);
			continue;
		}
		if(c-3>=n-c){
			//printf("c %d n %d\n",c,n);
			char m2=s[c+1];
			swap(s[2],s[c+1]);
			if(s[2]==s[c+2]){
				if(c+cnt[m2-'a']==n){
					for(int i=1; i<=n; i++)
						if(i>=2&&i<=cnt[m2-'a']+1) s[i]=m2;
						else s[i]=mi;
				}else swap(s[c+2],s[c+cnt[m2-'a']+1]);
			}
			puts(s+1);
		}else{
			t[1]=mi;
			int w1=c+1;
			c--;
			int w=2;
			if(c>0) t[w++]=mi,c--;
			while(w<=n){
				if(w1<=n) t[w++]=s[w1++];
				if(c>0) t[w++]=mi,c--;
			}
			t[n+1]=0;
			puts(t+1);
		}
	}
	return 0;
}