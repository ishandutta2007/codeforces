#include<bits/stdc++.h>
using namespace std;
struct suf
{
	int ind;
	int g,h;
};
int k;
int n;
int tl;
char s[2500000];
int p[2500000];
int b[2500000];
int mi[2][2500000];
bool pos[2500000];
int c[2500000];
vector<suf> a;
suf t;
bool operator <(suf x,suf y)
{
	return x.g<y.g || (x.g==y.g && x.h<y.h);
}
void solve()
{
	int m=p[0];
	for(int i=1;i<n;i++) m=min(m,p[i]);
	mi[0][0]=p[0];
	for(int i=1;i<n;i++) mi[0][i]=min(mi[0][i-1],p[i]);
	mi[1][n-1]=p[n-1];
	for(int i=n-2;i>=0;i--) mi[1][i]=min(mi[1][i+1],p[i]);
	for(int i=0;i<n;i++) {
		if(i==0) {
			if(mi[1][i]>=k) pos[i]=true;
		}
		else {
			if(min(mi[1][i]-p[i-1],(tl-p[i-1])+mi[0][i-1])>=k) pos[i]=true;
		}
	}
	//cout<<m<<endl;
	for(int i=0;i<n;i++) s[i+n]=s[i];
	n=2*n;
	for(int i=0;i<n;i++) {
		t.ind=i;
		if(s[i]=='(') t.g=0;
		else t.g=1;
		t.h=0;
		a.push_back(t);
	}
	int l=0;
	//sort(a.begin(),a.end(),byval);
	for(int i=1;i<n;i=i*2) {
		//sort(a.begin(),a.end(),byind);
		for(int j=0;j<a.size();j++) {
			c[a[j].ind]=j;
		}
		for(int j=0;j<a.size();j++) {
			if(a[j].ind+i<n) a[j].h=a[c[a[j].ind+i]].g;
			else a[j].h=-1;
		}
		sort(a.begin(),a.end());
		l=0;
		b[0]=0;
		for(int j=1;j<a.size();j++) {
			if(a[j].g!=a[j-1].g || a[j].h!=a[j-1].h) l++; 
			b[j]=l;
		}
		for(int j=0;j<a.size();j++) {
			//cout<<a[j].g<<" "<<
			a[j].g=b[j];
			a[j].h=0;
		}
	}
	int r=-1;
	for(int i=0;i<a.size();i++) {
		//cout<<a[i].ind<<endl;
		if(pos[a[i].ind]) {
			r=a[i].ind;
			break;
		}
	}
	n=n/2;
	//cout<<r<<endl;
	for(int i=r;i<n;i++) printf("%c",s[i]);
	for(int i=0;i<r;i++) printf("%c",s[i]);
}
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++) {
		if(s[i]=='(') p[i]++;
		else p[i]--;
		p[i+1]=p[i];
		//cout<<i<<" "<<p[i]<<endl;
	}
	//cout<<p[n]<<endl;
	if(p[n]<0) k=p[n];
	else k=0;
	tl=p[n];
	if(p[n]>=0) {
		solve();
		while(p[n]>0) {
			p[n]--;
			printf(")");
		}
	}
	else {
		while(p[n]<0) {
			p[n]++;
			printf("(");
		}
		solve();
	}
	return 0;
}