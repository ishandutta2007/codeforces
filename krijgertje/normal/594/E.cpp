#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;  

#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  

const int MAXLEN=5000000;

char s[MAXLEN+1]; int slen,maxpart;
int l[MAXLEN],nl;
char t[2*MAXLEN+2]; int tlen;
int z[2*MAXLEN+1];


bool sequal(int a,int b,int c,int d) { if(b-a!=d-c) return false; REPE(i,b-a) if(s[a+i]!=s[c+i]) return false; return true; }
int rcmp(int a,int b) { while(a<b) if(s[a]!=s[b]) return s[a]<s[b]?-1:+1; else ++a,--b; return 0; }
void buildl() { int k=slen; while(k>0) { int i=k-1,j=k-2; while(true) { if(j<0||s[i]>s[j]) { do { k-=i-j; l[nl++]=k+i-j-1; } while(k>i); break; } else if(s[i]<s[j]) i=k-1,--j; else --i,--j; } } }
void buildz() { int l=0,r=0; z[0]=tlen; FOR(i,1,tlen) if(i>r) { l=r=i; while(r<tlen&&t[r-l]==t[r]) ++r; z[i]=r-l; --r; } else { int k=i-l; if(z[k]<r-i+1) z[i]=z[k]; else { l=i; while(r<tlen&&t[r-l]==t[r]) ++r; z[i]=r-l; --r; } } }
int zcmp(int a,int b) { if(a+z[a]>b) return 0; char c1=t[z[a]],c2=t[a+z[a]]; return c2<c1?-1:+1; }
int minrot(int si) {
	int i=slen-1,j=i-1,k;
	while(j>=si) {
		for(k=0;k<slen-si&&s[i-k>=si?i-k:i-k+slen-si]==s[j-k>=si?j-k:j-k+slen-si];++k);
		if(s[i-k>=si?i-k:i-k+slen-si]<=s[j-k>=si?j-k:j-k+slen-si]) j-=k+1; else i-=k+1,i>j?i=j--:j=i-1;
	}
	return i;
}

char a[MAXLEN+1],b[MAXLEN+1],c[MAXLEN+1];

void run() {
	scanf("%s%d",&s,&maxpart); slen=strlen(s);
	buildl();

	REP(i,slen) t[slen-i-1]=t[slen+i+1]=s[i]; t[slen]='#'; tlen=2*slen+1; t[tlen]='\0';
	buildz();

	int si=0,li=nl-1,left=maxpart;
	while(si<slen&&li>=0&&left>=3) {
		if(l[li]==si) {
			int nsi=si,nli=li; while(nsi<slen&&l[nli]==nsi) ++nsi,--nli;
			si=nsi,li=nli; --left;
		} else {
			int nsi=l[li]+1,nli=li-1; while(nli>=0&&sequal(si,l[li],nsi,l[nli])) nsi=l[nli]+1,--nli;
			reverse(s+si,s+nsi);
			si=nsi,li=nli; --left;
		}
	}
	REPE(i,slen) a[i]=b[i]=c[i]=s[i];
	if(left==1) {
		reverse(b+si,b+slen);
	} else if(left==2&&si<slen&&li>=0) {
		int nli=li-1;
		for(;nli>=0;--nli) {
			int nla=l[nli+1]+1,nlb=l[nli],pla=nli==li-1?si:l[nli+2]+1,plb=l[nli+1];
			if(sequal(nla,nlb,pla,plb)) continue;
			if(nlb-nla<plb-si||!sequal(si,plb,nlb-plb+si,nlb)) break;
			int x=-rcmp(nla,nlb-plb+si-1);
			if(x==0) x=-rcmp(si,plb);
			if(x==+1) break;
		}
		reverse(a+si,a+l[nli+1]+1);
		int nsi=slen-1;
		for(int csi=nsi-1;csi>=si;--csi)  {
			int x=zcmp(slen+1+csi,slen+1+nsi-1);
			if(x==0) x=-zcmp(nsi-csi,slen-csi-1);
			if(x==+1) nsi=csi;
		}
		reverse(b+nsi,b+slen);
		nsi=minrot(si);
		reverse(c+si,c+nsi+1); reverse(c+nsi+1,c+slen);
	}
	//printf("%s\n%s\n%s\n",a,b,c);
	printf("%s\n",strcmp(a,b)<0?(strcmp(a,c)<0?a:c):(strcmp(b,c)<0?b:c));
}

int main() {
	run();
	return 0;
}