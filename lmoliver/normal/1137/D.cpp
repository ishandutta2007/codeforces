#include<bits/stdc++.h>
using namespace std;

#define F(p) for(int p=0;p<n;p++)

int g[10];
void read(){
	int k;
	if(scanf("%d",&k)==-1)exit(0);
	int c=0;
	for(int i=0;i<10;i++){
		int ch;
		do{
			ch=getchar();
			if(ch==' ')c++;
		}while(!isdigit(ch));
		g[ch^'0']=c;
	}
}

void go(int g1,int g2,int g3){
	printf("next");
	if(g1)for(int i=0;i<1;i++)printf(" %d",i);
	if(g2)for(int i=1;i<2;i++)printf(" %d",i);
	if(g3)for(int i=2;i<10;i++)printf(" %d",i);
	printf("\n");
	fflush(stdout);
	read();
}

int main(){
	int x=0;
	do{
		//1:fast 2:slow
		go(1,1,0);
		go(1,0,0);
		x++;
	}while(g[0]!=g[1]);
	do{
		go(1,1,1);
	}while(g[0]!=g[2]);
	printf("done");
	fflush(stdout);
    return 0;
}