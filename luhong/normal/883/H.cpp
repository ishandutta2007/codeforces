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
int n;
string str;
int fcts[1000],ff=0;
int cnt[1280];
int q1[1000],q2[1000],p1[1000],p2[1000],q,p;
char ans[4000001]; int a;
char tmp[4000001]; int tm;
int main(){
	scanf("%d",&n);
	F(i,1,n) if(n%i==0) fcts[++ff]=i;
	cin>>str;
	F2(i,0,n) ++cnt[str[i]];
	F(j,0,127) if(cnt[j]) {if(cnt[j]&1) q1[++q]=j, q2[q]=cnt[j]; else p1[++p]=j, p2[p]=cnt[j];}
//	F(qqwq,1,q) if(q2[qqwq]) printf("%c %d, ",q1[qqwq],q2[qqwq]); puts("");
//	F(ppwp,1,p) if(p2[ppwp]) printf("%c %d, ",p1[ppwp],p2[ppwp]); puts("");
	if(q==0){
		puts("1");
		while(tm<n/2&&p>=1){
			tmp[++tm]=p1[p]; p2[p]-=2;
			if(p2[p]==0) --p;
		}
		F(ll,1,n/2) putchar(tmp[ll]);
		dF(ll,n/2,1) putchar(tmp[ll]);
		return 0;
	}
	F(k,1,ff){
		int f=fcts[k];
		if(f<q) continue;
		if((f-q)&1) continue;
		if((n/f-1)&1) continue;
		int l=(n/f-1)/2;
		printf("%d\n",f);
		F(g,1,q) ans[++a]=q1[g], --q2[g];
		int qq=0;
		F(g,1,q) if(q2[g]) q1[++qq]=q1[g], q2[qq]=q2[g];
		q=qq;
//		F(qqwq,1,q) if(q2[qqwq]) printf("%c %d, ",q1[qqwq],q2[qqwq]); puts("");
//		F(ppwp,1,p) if(p2[ppwp]) printf("%c %d, ",p1[ppwp],p2[ppwp]); puts("");
		while(a<f&&q>=1){
			ans[++a]=q1[q]; --q2[q];
			if(q2[q]==0) --q;
		}
		while(a<f&&p>=1){
			ans[++a]=p1[p]; --p2[p];
			if(p2[p]==0) --p;
		}
		F(e,1,f){
			tm=0;
			while(tm<l&&q>=1){
				tmp[++tm]=q1[q]; q2[q]-=2;
				if(q2[q]==0) --q;
			}
			while(tm<l&&p>=1){
				tmp[++tm]=p1[p]; p2[p]-=2;
				if(p2[p]==0) --p;
			}
			F(ll,1,l) putchar(tmp[ll]);
			putchar(ans[e]);
			dF(ll,l,1) putchar(tmp[ll]);
			putchar(' ');
		}
		return 0;
	}
	return 0;
}