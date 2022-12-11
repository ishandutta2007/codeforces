#include<cstdio>

using namespace std;

char s[52];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d%s",&k,s+1);
		for(int i=1;i<=k;i++){
			int o=s[i]-'0';
			if(o!=2&&o!=3&&o!=5&&o!=7){
				printf("1\n%d\n",o);
				goto ed;
			}
		}
		for(int i=1;i<=k;i++)
			for(int j=i+1;j<=k;j++){
				int ok=1,o=(s[i]-'0')*10+s[j]-'0';
				for(int w=2;w<o;w++)
					if(o%w==0)ok=0;
				if(!ok){
					printf("2\n%d\n",o);
					goto ed;
				}
			}
		ed:;
	}
}