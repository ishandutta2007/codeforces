#include<cstdio>
#include<vector>
#include<cstdlib>
using namespace std;
const int N=200002;
int n,i,sa,ta,x[N],y[N],cnt;
char s[N],t[N];
vector<int>ab,ba;
void init(){
	scanf("%d%s%s",&n,s+1,t+1);
	for(i=1;i<=n;i++){
		if(s[i]=='a')
			sa++;
		if(t[i]=='a')
			ta++;
		if(s[i]=='a'&&t[i]=='b')
			ab.push_back(i);
		if(s[i]=='b'&&t[i]=='a')
			ba.push_back(i);			
	}
	if(sa+ta&1){
		printf("-1");
		exit(0);
	}
}
void work(){
	while(ab.size()>1){
		cnt++;
		x[cnt]=ab.back();
		ab.pop_back();
		y[cnt]=ab.back();
		ab.pop_back();
	}
	while(ba.size()>1){
		cnt++;
		x[cnt]=ba.back();
		ba.pop_back();
		y[cnt]=ba.back();
		ba.pop_back();
	}
	if(ab.size()){
		cnt++;
		x[cnt]=ab.back();
		y[cnt]=ab.back();
		cnt++;
		x[cnt]=ab.back();
		y[cnt]=ba.back();
	}
	printf("%d\n",cnt);
	for(i=1;i<=cnt;i++)
		printf("%d %d\n",x[i],y[i]);
}
int main(){
	init();
	work();
	return 0;
}