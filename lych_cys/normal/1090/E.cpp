#include<bits/stdc++.h>

using namespace std;

int a[8][8]={
	42,33,26,9,62,13,28,11,
	25,8,41,58,27,10,63,14,
	34,43,32,61,40,59,12,29,
	7,24,57,50,31,64,15,52,
	44,35,46,39,60,51,30,1,
	23,6,49,56,47,18,53,16,
	36,45,4,21,38,55,2,19,
	5,22,37,48,3,20,17,54
};
int n,f[100],g[100],ans,out[3000],c[100][2];
char s[2];

void decode(int x){
	putchar(c[x][0]+'a'); putchar(c[x][1]+'1');
}

int main(){
	scanf("%d",&n);
	for (int i=0;i<8;++i)
		for (int j=0;j<8;++j) --a[i][j];
	for (int i=0;i<n;++i){
		scanf("%s",s);
		int x=s[0]-'a',y=s[1]-'1';
		f[a[x][y]]=1;
	}
	for (int i=0;i<8;++i)
		for (int j=0;j<8;++j) c[a[i][j]][0]=i,c[a[i][j]][1]=j;
	for (int i=0;i<n;++i) g[a[i%8][i/8]]=1;
	while (1){
		bool fl=0;
		for (int i=0;i<64;++i)
			if (f[i]==1&&g[i]==0){
				for (int j=i;;j=(j+1)%64)
					if (f[j]&&!f[(j+1)%64]){
						fl=1;
						out[++ans]=j;
						f[j]=0;
						f[(j+1)%64]=1;
						break;
					}
				break;
			}
		if (!fl) break;
	}
	printf("%d\n",ans);
	for (int i=1;i<=ans;++i){
		int x=out[i],y=(out[i]+1)%64;
		decode(x); putchar('-'); decode(y); puts("");
	}
	
	return 0;
}