#include<bits/stdc++.h>
using namespace std;
int n;
char b[3001][3001];
char f[3001][3001];
char s[5001];
char t[5001];
int r[5001];
char pref[5001];
char suf[5001];
char tot[5001];
bool id[5001];
int le[5001];
int fd;
pair<int,int> cd[5001];
long long hv[5001];
int l;
long long mod=1000000007;
long long pv=10007;
long long sv;
long long lv;
void hs(int i) {
	if(i==-1) {
		long long br=1;
		for(int j=1;j<l;j++) br=(br*pv)%mod;
		sv=br;
		br=1;
		for(int j=0;j<l;j++) {
			lv=(lv+br*(s[j]-'a'+1))%mod;
			br=(br*pv)%mod;
		}
	}
	else {
		int m=le[i];
		long long br=1;
		for(int j=0;j<=m;j++) hv[j]=0;
		//cout<<sv<<endl;
		for(int j=0;j<l;j++) {
			hv[m-1]=(hv[m-1]+br*(b[i][m-l+j]-'a'+1))%mod;
			br=(br*pv)%mod;
		}
		for(int j=m-2;j>=l-1;j--) {
			hv[j]=hv[j+1];
			hv[j]-=sv*(b[i][j+1]-'a'+1);
			hv[j]%=mod;
			if(hv[j]<0) hv[j]+=mod;
			hv[j]*=pv;
			hv[j]+=(b[i][j-l+1]-'a'+1);
			hv[j]%=mod;
		}
	}
}
pair<int,int> choice(int i) {
	int g=le[i],h=-1;
	int m=le[i];
	for(int j=0;j<m;j++) {
		if(b[i][j]!=f[i][j]) {
			g=min(g,j);
			h=max(h,j);
		}
	}
	//cout<<g<<" "<<h<<endl;
	return make_pair(g,h);
	//kmp(i);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%s",b[i]);
	for(int i=0;i<n;i++) scanf("%s",f[i]);
	int c=0;
	int m;
	pair<int,int> ch;
	int g,h;
	for(int i=0;i<n && c!=-1;i++) {
		le[i]=strlen(b[i]);
		m=le[i];
		id[i]=true;
		for(int j=0;j<m;j++) {
			if(b[i][j]!=f[i][j]) {
				id[i]=false;
				break;
			}
		}
		if(!id[i]) { //Nisu isti
			fd=i;
			if(c==0) {
				c=1;
				cd[i]=choice(i);
				g=cd[i].first;
				h=cd[i].second;
				//cout<<g<<" "<<h<<endl;
				for(int j=g;j<=h;j++) {
					s[j-g]=b[i][j];
					t[j-g]=f[i][j];
					//cout<<j-g<<endl;
				}
				//printf("%s\n%s\n",s,t);
				l=h-g+1;
			}
			else {
				if(c==1) {
					cd[i]=choice(i);
					g=cd[i].first;
					h=cd[i].second;
					if(l!=h-g+1) c=-1;
					for(int j=g;j<=h && c!=-1;j++) {
						if(s[j-g]!=b[i][j]) c=-1;
						if(t[j-g]!=f[i][j]) c=-1;
					}
				}
			}
		}
		else cd[i]=make_pair(0,le[i]);
	}
	if(c==-1) printf("NO");
	else { //Ako je sta moguce, mora da bude bar ovo.
		int sz=0,ps=0;
		bool pos=true;
		for(int j=cd[fd].first-1;pos && j>=0;j--) {
			pos=true;
			for(int i=0;i<n;i++) {
				if(!id[i]) {
					if(cd[i].first<=sz || b[fd][cd[fd].first-sz-1]!=b[i][cd[i].first-sz-1]) {
						pos=false;
					}
				}
			}
			if(pos) sz++;
		}
		for(int j=cd[fd].first-sz;j<cd[fd].first;j++) pref[j-(cd[fd].first-sz)]=b[fd][j];
		ps=sz;
		pos=true;
		m=le[fd];
		sz=0;
		for(int j=cd[fd].second+1;pos && j<m;j++) {
			pos=true;
			for(int i=0;i<n;i++) {
				if(!id[i]) {
					if(cd[i].second+sz+1>=le[i] || b[fd][cd[fd].second+sz+1]!=b[i][cd[i].second+sz+1]) {
						pos=false;
					}
				}
			}
			if(pos) sz++;
		}
		for(int j=cd[fd].second+1;j<=cd[fd].second+sz;j++) suf[j-(cd[fd].second+1)]=b[fd][j];
		m=ps+l+sz;
		//printf("%s\n%s\n",s,t);
		for(int i=0;i<ps;i++) tot[i]=pref[i];
		for(int i=0;i<l;i++) tot[i+ps]=t[i];
		for(int i=0;i<sz;i++) tot[i+ps+l]=suf[i];
		for(int i=0;i<m;i++) t[i]=tot[i];
		for(int i=0;i<ps;i++) tot[i]=pref[i];
		for(int i=0;i<l;i++) tot[i+ps]=s[i];
		for(int i=0;i<sz;i++) tot[i+ps+l]=suf[i];
		for(int i=0;i<m;i++) s[i]=tot[i];
		l=m;
		hs(-1);
		//cout<<s<<" "<<t<<endl;
		//cout<<lv<<endl;
		for(int i=0;i<n && c!=-1;i++) {
			hs(i);
			//cout<<i<<endl;
			for(int j=0;j<cd[i].second;j++) {
				//cout<<"\t"<<j<<" "<<hv[j]<<endl;
				if(hv[j]==lv) {
					c=-1;
					break;
				}
			}
		}
		if(c==-1) printf("NO");
		else {
			printf("YES\n");
			printf("%s\n",s);
			printf("%s\n",t);
		}
	}
	return 0;
}