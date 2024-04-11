#include<cstdio>
const int N=300002;
int n,m,p[3],i;
char s[N];
int main(){
	scanf("%d%s",&n,s+1);
	m=n/3;
	for(i=1;i<=n;i++)
		p[s[i]-48]++;
	if(p[0]<m){
		for(i=1;i<=n&&p[0]<m;i++)
			if(p[s[i]-48]>m){
				p[s[i]-48]--;
				p[0]++;
				s[i]='0';
			}
	}
	if(p[0]>m){
		for(i=n;i&&p[0]>m;i--)
			if(s[i]=='0'){
				if(p[2]<m){
					p[2]++;
					p[0]--;
					s[i]='2';
				}
				else{
					p[1]++;
					p[0]--;
					s[i]='1';
				}
			}			
	}	
	if(p[2]<m){
		for(i=n;i&&p[2]<m;i--)
			if(p[s[i]-48]>m){
				p[s[i]-48]--;
				p[2]++;
				s[i]='2';
			}
	}
	if(p[2]>m){
		for(i=1;i<=n&&p[2]>m;i++)
			if(s[i]=='2'){
				if(p[0]<m){
					p[0]++;
					p[2]--;
					s[i]='0';
				}
				else{
					p[1]++;
					p[2]--;
					s[i]='1';
				}
			}			
	}
	printf("%s",s+1);
	return 0;
}