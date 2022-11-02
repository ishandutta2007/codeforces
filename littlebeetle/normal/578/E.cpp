#include<cstdio>
#include<vector>
using namespace std;
const int N=100002;
int n,i,j,k,LstL,LstR,a,b;
int t[N],pre[N],deg[N],Ans,val[N],cnt;
char s[N];
struct Uzi{
	int a,b;
}x;
vector<Uzi>LL,RR,LR,RL;
void add(int a,int b){
	t[a]=b;
	pre[b]=a;
	deg[b]++;
}
void init(){
	scanf("%s",s+1);
	while(s[n+1])
		n++;
	Ans=n-1;
	for(i=1;i<=n;i++)
		if(s[i]=='L'){
			LstR=max(LstR+1,i+1);
			while(LstR<=n&&s[LstR]=='L')
				LstR++;
			if(LstR<=n){
				add(i,LstR);
				Ans--;
			}
		}
		else{
			LstL=max(LstL+1,i+1);
			while(LstL<=n&&s[LstL]=='R')
				LstL++;
			if(LstL<=n){
				add(i,LstL);
				Ans--;
			}
		}
	printf("%d\n",Ans);		
}
void work(){
	for(a=1;a<=n;a++)
		if(deg[a]==0){
			b=a;
			for(j=t[a];j;j=t[j])
				b=j;
			//printf("%d %d\n",a,b);
			if(s[a]=='L'&&s[b]=='L')
				LL.push_back((Uzi){a,b});
			if(s[a]=='L'&&s[b]=='R')
				LR.push_back((Uzi){a,b});
			if(s[a]=='R'&&s[b]=='L')
				RL.push_back((Uzi){a,b});
			if(s[a]=='R'&&s[b]=='R')
				RR.push_back((Uzi){a,b});				
		}
	while(LL.size()&&RR.size()){
		add((LL.back()).b,(RR.back()).a);
		LR.push_back((Uzi){(LL.back()).a,(RR.back()).b});
		LL.pop_back();
		RR.pop_back();
	}
	while(LR.size()>1){
		i=LR.size()-2;
		j=LR.size()-1;	
		add(LR[i].b,LR[j].a);
		x=(Uzi){LR[i].a,LR[j].b};
		LR.pop_back();
		LR.pop_back();
		LR.push_back(x);
	}
	while(RL.size()>1){
		i=RL.size()-2;
		j=RL.size()-1;	
		add(RL[i].b,RL[j].a);
		x=(Uzi){RL[i].a,RL[j].b};
		RL.pop_back();
		RL.pop_back();
		RL.push_back(x);
	}
	//printf("%d %d %d %d\n",LL.size(),RR.size(),LR.size(),RL.size());
	if(LL.size()){
		if(LR.size()){
			add((LR.back()).b,(LL.back()).a);
			x=(Uzi){(LR.back()).a,(LL.back()).b};
			LR.pop_back();
			LL.pop_back();
			LL.push_back(x);
		}
		if(RL.size()){
			add((LL.back()).b,(RL.back()).a);
			x=(Uzi){(LL.back()).a,(RL.back()).b};
			LL.pop_back();
			RL.pop_back();
			LL.push_back(x);
		}
	}
	if(RR.size()){
		if(LR.size()){
			add((RR.back()).b,(LR.back()).a);
			x=(Uzi){(RR.back()).a,(LR.back()).b};
			RR.pop_back();
			LR.pop_back();
			RR.push_back(x);
		}
		if(RL.size()){
			add((RL.back()).b,(RR.back()).a);
			x=(Uzi){(RL.back()).a,(RR.back()).b};
			RL.pop_back();
			RR.pop_back();
			RR.push_back(x);
		}
	}
	//printf("     %d %d %d  %d\n",(LR.back()).a,(LR.back()).b,pre[(LR.back()).b],n);
	//printf("     %d %d\n",(RL.back()).a,(RL.back()).b);	
	if(LR.size()&&RL.size()){
		/*if((LR.back()).a==(LR.back()).b)
			add((LR.back()).a,(RL.back()).a);
		else
		if((RL.back()).a==(RL.back()).b)
			add((RL.back()).a,(LR.back()).a);*/
		if((LR.back()).b>(RL.back()).b){
			add(pre[(LR.back()).b],(RL.back()).a);
			add((RL.back()).b,(LR.back()).b);
		}
		else{
			add(pre[(RL.back()).b],(LR.back()).a);
			add((LR.back()).b,(RL.back()).b);
		}
	}
	//printf("%d %d %d %d\n",LL.size(),RR.size(),LR.size(),RL.size());
	/*for(i=1;i<=n;i++)
		if(deg[i]==0)
			printf("%d\n",i);*/
	for(i=1;i<=n;i++)
		if(deg[i]==0)
			break;
	for(;i;i=t[i])
		val[++cnt]=i;
	for(i=1;i<=n;i++)
		printf("%d ",val[i]);
}
int main(){
	init();
	work();
	return 0;
}