#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T,n,m,tot;char s[N];string anss;
bool all0(){for(int i=1;i<=n;i++)if(s[i]=='1')return 0;return 1;}
void append(int l,int r){tot++,anss+=to_string(l)+" "+to_string(r)+"\n";}
void solve2(int l,int r,int k,int p,int typ){
	if(k==p){for(int i=l;i<=r;i++)append(i,i);return;}
	int i;
	for(i=l;s[i]=='0';i++)append(i,i);
	if(s[i+1]=='1')append(i,i+1),solve2(i+2,r,k-2,p-3,0);
	else append(i,i+1),solve2(i+2,r,k-1,p-2,0);
}
void solve(int l,int r,int k,int p){
	if(k==p){for(int i=l;i<=r;i++)append(i,i);return;}
	if(k==3){int i;for(i=l;s[i]=='0';i++)append(i,i);append(i,i+1);for(i+=2;i<=r;i++)append(i,i);return;}
	if(k==5){
		int i;
		for(i=l;s[i]=='0';i++)append(i,i);
		if(s[i+1]=='1'&&s[i+2]=='1'&&s[i+3]=='1'&&s[i+4]=='1'){append(i,i+3),append(i+4,i+4);for(i+=5;i<=r;i++)append(i,i);}
		else{for(;s[i+1]=='1';i++)append(i,i);append(i,i+2);for(i+=3;i<=r;i++)append(i,i);}
		return;
	}
	if(k==4&&p==8){
		int i;
		for(i=l;s[i]=='0';i++)append(i,i);
		append(i,i+2),solve2(i+3,r,3-(s[i+1]=='1')-(s[i+2]=='1'),4-2*int(s[i+1]=='1')-(s[i+2]=='1'),-1);
		return;
	}
	if(k>=12||k==8&&p==16){
		int t=k>>1;
		for(int i=l,c=0;;i++){
			c+=(s[i]=='1');
			if(c==t){solve(l,i,t,p>>1),solve(i+1,r,k-t,p>>1);return;}
		}
	}
	if(k>=6&&k<=8){solve2(l,r,k,p,1);return;}
	if(k==11){solve2(l,r,k,p,-1);return;}
	if(k==9){
		int i;
		for(i=l;s[i]=='0';i++)append(i,i);
		if(s[i+1]=='1'){append(i,i+2),solve2(i+3,r,6+(s[i+2]=='0'),9+(s[i+2]=='0'),2);}
		else if(s[i+2]=='0'){append(i,i+2),solve2(i+3,r,8,12,3);}
		else{
			append(i,i+2);
			for(i+=3;s[i]=='0';i++)append(i,i);
			if(s[i+1]=='1'){append(i,i+2);for(i+=3;i<=r;i++)append(i,i);}
			else{append(i,i+1),solve2(i+2,r,6,9,4);}
		}
		return;
	}
	if(k==10){
		int i;
		for(i=l;s[i]=='0';i++)append(i,i);
		append(i,i+2),solve2(i+3,r,9-(s[i+1]=='1')-(s[i+2]=='1'),12-2*int(s[i+1]=='1')-(s[i+2]=='1'),5);
		return;
	}
}
void solve(){
	scanf("%s",s+1),n=strlen(s+1);
	if(all0()){printf("-1\n");return;}
	tot=m=0,anss="";
	for(int i=1;i<=n;i++)m+=s[i]-'0';
	int k=1;while(k<m)k<<=1;
	solve(1,n,m,k);
	cout<<tot<<"\n"<<anss;
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
//iee