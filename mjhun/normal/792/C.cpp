#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

void perdi(){puts("-1");exit(0);}

char s[100005];int n;
bool e[100005];
int q[3];

void q0(){
	bool a=false;
	int l=0;
	fore(i,0,n){
		if(e[i]&&s[i]=='0')e[i]=false;
		if(e[i]&&s[i]!='0'){
			a=true;
			break;
		}
	}
	if(!a){
		fore(i,0,n)if(s[i]=='0'){e[i]=true;break;}
	}
}

void qq(int k){
	for(int i=n-1;i>=0;--i)if(e[i]&&(s[i]-'0')%3==k){e[i]=false;break;}
	q0();
}

int nt(){int r=0;fore(i,0,n)r+=e[i];return r;}
void q1(){qq(1);}
void q2(){qq(2);}

int main(){
	scanf("%s",s);n=strlen(s);
	memset(e,true,sizeof(e));
	fore(i,0,n)q[(s[i]-'0')%3]++;
	int k=(q[1]+2*q[2])%3;
	if(k==0)q0();
	else if(k==1){
		int a=-1,b=-1;
		if(!q[0]&&q[1]==1&&!q[2])perdi();
		if(!q[0]&&!q[1]&&q[2]<=2)perdi();
		if(q[1]){
			q1();
			a=nt();
		}
		if(q[2]>=2){
			memset(e,true,sizeof(e));
			q2();q2();
			b=nt();
		}
		if(a>b){
			memset(e,true,sizeof(e));
			q1();
		}
		else {
			memset(e,true,sizeof(e));
			q2();q2();
		}
	}
	else {
		int a=-1,b=-1;
		if(!q[0]&&!q[1]&&q[2]==1)perdi();
		if(!q[0]&&q[1]<=2&&!q[2])perdi();
		if(q[2]){
			q2();
			a=nt();
		}
		if(q[1]>=2){
			memset(e,true,sizeof(e));
			q1();q1();
			b=nt();
		}
		if(a>b){
			memset(e,true,sizeof(e));
			q2();
		}
		else {
			memset(e,true,sizeof(e));
			q1();q1();
		}
	}
	fore(i,0,n)if(e[i])putchar(s[i]);
	puts("");
	return 0;
}