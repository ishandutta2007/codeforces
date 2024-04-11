#include<cstdio>
const int N=200002*32;
int q,cnt=1,i,j,t[N][2],s[N],d[N],x,y;
char ch[3];
void add(int x){
	for(i=30,j=1;i>=0;i--){
		if(!t[j][x>>i&1])
			t[j][x>>i&1]=++cnt;
		j=t[j][x>>i&1];
		s[j]++;
	}
}
int main(){
	scanf("%d",&q);
	add(0);
	while(q--){
		scanf("%s%d",ch,&x);
		if(*ch=='+')
			add(x);
		if(*ch=='-'){
			for(i=30,j=1;i>=0;i--){
				j=t[j][x>>i&1];
				s[j]--;
			}
		}	
		if(*ch=='?'){
			y=0;
			for(i=30,j=1;i>=0;i--){
				if(s[t[j][x>>i&1^1]])
					j=t[j][x>>i&1^1],y+=1<<i;
				else
					j=t[j][x>>i&1];
			}
			printf("%d\n",y);			
		}
	}
	//while(1);
}