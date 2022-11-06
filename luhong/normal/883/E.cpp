#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#define F(i,a,b) for(int i=a;i<=b;++i)
#define dF(i,a,b) for(int i=a;i>=b;--i)
#define F2(i,a,b) for(int i=a;i<b;++i)
#define dF2(i,a,b) for(int i=(long long)a-1;i>=b;--i)
using namespace std;
int n,m;
string q;
string strs[1009];
bool use[50];
int u[1009];
int main(){
	scanf("%d",&n);
	cin>>q;
	F2(i,0,n) if(q[i]>='a'&&q[i]<='z') use[q[i]-'a']=1;
	scanf("%d",&m);
	int t=0;
	F(i,1,m){
		cin>>strs[++t];
		F2(j,0,n){
			if(q[j]>='a'&&q[j]<='z'){
				if(strs[t][j]!=q[j]) {--t; break;}
			}
			else{
				if(use[strs[t][j]-'a']) {--t; break;}
			}
		}
	}
	int ans=~0;
	F(i,1,t){
//		cout<<strs[i]<<endl;
		F2(j,0,n){
			if(q[j]=='*'){
				u[i]|=(1<<(strs[i][j]-'a'));
			}
		}
		ans&=u[i];
	}
	int Ans=0;
	while(ans) {++Ans; ans-=ans&-ans;}
	printf("%d",Ans);
	return 0;
}