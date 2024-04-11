//%%%%%%%%%%%%
//%%%     %%%%
//%%%%%%%%%%%%
#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,len;
char c[1005],s[55],t[55];
int kmp1[55],kmp2[55],nxt1[55][26],nxt2[55][26];
int f[1005][55][55];
inline void build(char s[],int n,int kmp[],int nxt[][26]){
	 for(int i=2,j=0;i<=n;i++){
            while(j>0&&s[i]!=s[j+1]) j=kmp[j];
            if(s[i]==s[j+1]) j++;
            kmp[i]=j;
        } 
    for(int i=0;i<=n;i++)
    	for(int j=0;j<26;j++){
    		int t=i;
    		while(t>0&&s[t+1]!=j+'a') t=kmp[t];
			if(s[t+1]==j+'a') t++;
			nxt[i][j]=t;
		}
}
int main(){
	scanf("%s",c+1);scanf("%s",s+1);scanf("%s",t+1);
	len=strlen(c+1);n=strlen(s+1);m=strlen(t+1);
	build(s,n,kmp1,nxt1);build(t,m,kmp2,nxt2);
	memset(f,-0x3f,sizeof(f));
	f[0][0][0]=0;
	for(int i=0;i<len;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=m;k++)
				for(int ch=0;ch<26;ch++){
					if(c[i+1]=='*'||c[i+1]==ch+'a'){
						int ns=nxt1[j][ch],nt=nxt2[k][ch];
						f[i+1][ns][nt]=max(f[i+1][ns][nt],f[i][j][k]+(ns==n)-(nt==m));
					}
				}
	int ans=-0x3f3f3f3f;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			ans=max(ans,f[len][i][j]);
	cout<<ans;
	return 0;
}